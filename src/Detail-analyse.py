import sys
import cv2
import time
import shutil
import base64
import os
from enum import Enum
from typing import Optional, List
from openai import OpenAI
# 通过 pip install volcengine-python-sdk[ark] 安装方舟SDK
from volcenginesdkarkruntime._exceptions import ArkAPIError
from volcenginesdkarkruntime import Ark
import ffmpeg
import io

#关键帧分析：火山引擎
#音频分析：阿里云百炼
#综合分析：阿里云百炼
#现在想要实现的是流式输出，接下来要解决的是API调用和Qt上是否支持流式输出！


#视频抽帧图片分析部分
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding="utf-8")
global result_of_voice
global result_of_images

class Strategy(Enum):
    CONSTANT_INTERVAL = "constant_interval"  # 固定间隔抽帧
    EVEN_INTERVAL = "even_interval"  # 均匀间隔抽帧

ARK_API_KEY = "d4e09ca3-1ac7-4238-bfbb-f1d686e1f505"  # 提升为全局常量
MODEL_ID = "doubao-1-5-vision-pro-32k-250115"  # 修正模型版本号
prompt = "分析视频中的内容，50字以内"

def preprocess_video(video_file_path: str, output_dir: str,
                     extraction_strategy: Optional[Strategy] = Strategy.EVEN_INTERVAL,
                     interval_in_seconds: Optional[float] = 1, max_frames: Optional[int] = 10,
                     keyframe_naming_template: str = "frame_{:04d}.jpg") -> List[str]:
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    cap = cv2.VideoCapture(video_file_path)
    fps = cap.get(cv2.CAP_PROP_FPS)
    length = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))

    if extraction_strategy == Strategy.CONSTANT_INTERVAL:
        frame_interval = max(1, int(fps * interval_in_seconds))
    elif extraction_strategy == Strategy.EVEN_INTERVAL:
        frame_interval = max(1, length // max_frames)
    else:
        raise ValueError("Invalid extraction strategy")

    frame_count = 0
    keyframes = []
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        if frame_count % frame_interval == 0:
            image_path = os.path.join(output_dir, keyframe_naming_template.format(len(keyframes)))
            cv2.imwrite(image_path, frame)
            keyframes.append(image_path)
        frame_count += 1
        if len(keyframes) >= max_frames:
            break

    return keyframes


def resize(image):
    height, width = image.shape[:2]
    target_height, target_width = (480, 640) if height < width else (640, 480)
    if height <= target_height and width <= target_width:
        return image
    if height / target_height < width / target_width:
        new_width = target_width
        new_height = int(height * (new_width / width))
    else:
        new_height = target_height
        new_width = int(width * (new_height / height))
    return cv2.resize(image, (new_width, new_height))


def encode_image(image_path: str) -> str:
    image = cv2.imread(image_path)
    image_resized = resize(image)
    _, encoded_image = cv2.imencode(".jpg", image_resized)
    return base64.b64encode(encoded_image).decode("utf-8")


def construct_messages(image_paths: List[str], prompt: str) -> List[dict]:
    content = [{"type": "text", "text": prompt}]
    for image_path in image_paths:
        content.append({
            "type": "image_url",
            "image_url": {
                "url": f"data:image/jpeg;base64,{encode_image(image_path)}",
                "detail": "low"
            },
        })
    return [{"role": "user", "content": content}]


def main(video_path: str):
    global message_of_images


    # ========== 参数校验优化 ==========
    if not os.path.isfile(video_path):   # 强化路径校验
        print(f"[ERROR] 无效视频路径: {video_path}")
        sys.exit(1)

    # ========== 创建临时目录 ==========
    output_dir = os.path.join(os.getcwd(),  "videoFrames")
    try:
        if os.path.exists(output_dir):
            shutil.rmtree(output_dir)
        os.makedirs(output_dir,  exist_ok=True)
    except OSError as e:
        print(f"[ERROR] 目录操作失败: {e}")
        sys.exit(1)

    # ========== 视频处理 ==========
    try:
        selected_images = preprocess_video(
            video_file_path=video_path,
            output_dir=output_dir,
            extraction_strategy=Strategy.CONSTANT_INTERVAL,
            interval_in_seconds=1,
            max_frames=20
        )
    except Exception as e:
        print(f"[ERROR] 视频处理失败: {e}")
        sys.exit(1)

    # ========== API调用优化 ==========
    client = Ark(api_key=ARK_API_KEY)  # 使用全局常量
    try:
        # 启用流式输出
        response = client.chat.completions.create(
            model=MODEL_ID,
            messages=construct_messages(selected_images, prompt),
            stream=True,  # 关键：开启流式传输
        )
        # 用于存储完整的文本内容
        message_of_images = ""

        # 实时输出内容
        print("【视频关键帧分析结果】", end="", flush=True)

        #用于流式输出结果
        for chunk in response:
            if chunk.choices  and len(chunk.choices)  > 0:
                chunk_message = chunk.choices[0].delta.content
                if chunk_message is not None:
                    message_of_images += chunk_message  # 直接拼接字符串
                    print(chunk_message, end='', flush=True)


    except ArkAPIError as e:
        print(f"[API ERROR] 服务调用失败: {e.code}  - {e.message}")
        sys.exit(1)
    except Exception as e:
        print(f"[ERROR] 未知错误: {str(e)}")
        sys.exit(1)



def extract_audio_from_video(video_path):
    global mp3_path
    """
    从 MP4 视频中提取音频并保存为 MP3，存放到同目录的 MP3 文件夹中
    :param video_path: MP4 视频文件路径
    """
    if not os.path.exists(video_path):
        print(f"❌ 文件不存在: {video_path}")
        return

    # 获取视频所在目录和文件名（不含扩展名）
    video_dir = os.path.dirname(video_path)
    video_name = os.path.splitext(os.path.basename(video_path))[0]

    # 创建 MP3 目录
    mp3_dir = os.path.join(video_dir, "MP3")
    os.makedirs(mp3_dir, exist_ok=True)

    # 生成 MP3 文件路径
    mp3_path = os.path.join(mp3_dir, f"{video_name}.mp3")

    # 执行 ffmpeg 提取音频
    try:
        ffmpeg.input(video_path).output(mp3_path, format="mp3", audio_bitrate="192k").run(overwrite_output=True)
        print(f"✅ 音频已成功提取: {mp3_path}")
    except ffmpeg.Error as e:
        print(f"❌ ffmpeg 处理失败: {e}")




#音频分析部分
def mainOfVoice(voice_path: str):
    global message_of_voice

    client = OpenAI(

        api_key="sk-e599f7779762406ca157d4e34e12dd69",
        base_url="https://dashscope.aliyuncs.com/compatible-mode/v1",
    )


    def encode_audio(audio_path):
        with open(audio_path, "rb") as audio_file:
            return base64.b64encode(audio_file.read()).decode("utf-8")


    base64_audio = encode_audio(voice_path)

    completion = client.chat.completions.create(
        model="qwen-omni-turbo",
        messages=[
            {
                "role": "system",
                "content": [{"type": "text", "text": "You are a helpful assistant."}],
            },
            {
                "role": "user",
                "content": [
                    {
                        "type": "input_audio",
                        "input_audio": {
                            "data": f"data:;base64,{base64_audio}",
                            "format": "mp3",
                        },
                    },
                    {"type": "text", "text": "分析这段音频，主要内容和情感是什么？"},
                ],
            },
        ],

        # stream 必须设置为 True，否则会报错
        stream=True,
        stream_options={"include_usage": True},
    )



    print("【音频分析结果】", end="", flush=True)

    # 用于存储完整的文本内容
    message_of_voice = ""


    #用于流式输出结果
    for chunk in completion:
        if chunk.choices  and len(chunk.choices)  > 0:
            chunk_message = chunk.choices[0].delta.content
            if chunk_message is not None:
                message_of_voice += chunk_message  # 直接拼接字符串
                print(chunk_message, end='', flush=True)




def mainOfBoth(result_of_images: str,result_of_voice: str):
    client = OpenAI(

        api_key="sk-e599f7779762406ca157d4e34e12dd69",
        base_url="https://dashscope.aliyuncs.com/compatible-mode/v1",
    )

    content="视频中的关键帧分析结果为："+message_of_images+",视频的音频分析结果为："+message_of_voice+",总结出这个视频的类别，前面标注“视频类别”，用6个词概括并用逗号隔开"
    completion = client.chat.completions.create(
        model="qwen-omni-turbo",
        messages=[{"role": "user", "content":content}],
#        # 设置输出数据的模态，当前仅支持["text"]
#        modalities=["text"],
        # stream 必须设置为 True，否则会报错
        stream=True,
        stream_options={"include_usage": True},
    )


    print("【综合分析结果】", end="", flush=True)


    for chunk in completion:
        if chunk.choices  and len(chunk.choices)  > 0:
            chunk_message = chunk.choices[0].delta.content
            if chunk_message is not None:
                print(chunk_message, end='', flush=True)






if __name__ == "__main__":
    # ========== 参数检查增强 ==========
    if len(sys.argv)  != 2:
        sys.exit(1)

    main(sys.argv[1])
    video_path=sys.argv[1]
    extract_audio_from_video(video_path)
    mainOfVoice(mp3_path)
    mainOfBoth(message_of_images,message_of_voice)
