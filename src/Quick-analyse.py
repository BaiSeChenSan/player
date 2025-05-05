import os
import base64
import re
import matplotlib.pyplot as plt
from openai import OpenAI
import shutil

import base64
import sys
import cv2
import time
import shutil
import base64
from enum import Enum
from typing import Optional, List
from openai import OpenAI
# 通过 pip install volcengine-python-sdk[ark] 安装方舟SDK
from volcenginesdkarkruntime._exceptions import ArkAPIError
from volcenginesdkarkruntime import Ark
import ffmpeg
import io


import sys
import cv2
import time
import ffmpeg
import io

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding="utf-8")

# 配置 API 客户端
client = OpenAI(
    api_key="sk-814bb34a29cf45ee9a98d18b00b9eebf",
    base_url="https://dashscope.aliyuncs.com/compatible-mode/v1",
)


def trim_audio_ffmpeg(input_path, output_path, start_time, duration):
    """
    使用 ffmpeg-python 截取视频
    :param input_path: 原始视频文件路径
    :param output_path: 截取后视频文件路径
    :param start_time: 开始时间（秒）
    :param duration: 截取时长（秒）
    """

    ffmpeg.input(input_path, ss=start_time, t=duration).output(output_path).run(overwrite_output=True, quiet=True)
    print(f"✅ 视频已成功截取并保存至 {output_path}")

def encode_audio(audio_path):
    """将视频文件编码为 base64 字符串"""
    with open(audio_path, "rb") as audio_file:
        return base64.b64encode(audio_file.read()).decode("utf-8")


def parse_emotion_percentages(text):
    """
    从文本中解析情感占比数据
    示例输入："分析结果显示：喜悦（30%）、悲伤（50%）、中立（20%）"
    返回：{"喜悦": 0.3, "悲伤": 0.5, "中立": 0.2}
    """
    pattern = r'([\u4e00-\u9fa5]+)[\s（(]*(\d+)%[）)]*'
    matches = re.findall(pattern, text)

    emotion_dict = {}
    total = 0
    for emotion, percent in matches:
        value = float(percent) / 100
        emotion_dict[emotion] = value
        total += value

    # 标准化处理（确保总和为1）
    if total > 0:
        return {k: v / total for k, v in emotion_dict.items()}
    return {}


def plot_emotion_pie(emotion_data):
    """绘制情感分布饼状图并保存到与脚本同目录下的 images 文件夹"""

    if not emotion_data:
        print("⚠️ 没有有效的情感数据可供可视化")
        return


    # 获取当前脚本所在目录
    script_dir = os.path.dirname(os.path.abspath(__file__))
    save_dir = os.path.join(script_dir, "images")

    # 创建 images 目录（如果不存在）
    if not os.path.exists(save_dir):
        os.makedirs(save_dir)

    labels = [f"{k} ({v * 100:.1f}%)" for k, v in emotion_data.items()]
    sizes = list(emotion_data.values())
    colors = ['#ff9999', '#66b3ff', '#99ff99', '#ffcc99', '#c2c2f0']

    plt.figure(figsize=(10, 7))
    plt.rcParams['font.sans-serif'] = ['SimHei']  # 解决中文显示问题
    plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题

    patches, texts, autotexts = plt.pie(
        sizes,
        labels=labels,
        colors=colors,
        autopct='%1.1f%%',
        startangle=90,
        pctdistance=0.85,
        wedgeprops={'linewidth': 1, 'edgecolor': 'white'}
    )

    for text in texts + autotexts:

        text.set_fontsize(40)
        text.set_color('#333333')
#去除环状效果
#    centre_circle = plt.Circle((0, 0), 0.70, fc='white')
#    plt.gca().add_artist(centre_circle)

    plt.title('视频情感分析结果分布', fontsize=40, pad=10)
    plt.axis('equal')
    plt.tight_layout()

    # 保存图片到 images 文件夹
    output_path = os.path.join(save_dir, f"emotion_pie_{int(time.time())}.png")
    plt.savefig(output_path, dpi=600, bbox_inches='tight')
    print(f"image_path:{output_path}")  # 输出图片路径到标准输出


# 主程序流程
if __name__ == "__main__":

    plt.ioff()  # 关闭交互式模式

    # ========== 参数检查增强 ==========
    if len(sys.argv) != 2:
        sys.exit(1)

    input_audio_path = sys.argv[1]
    trimmed_audio_path = input_audio_path.replace(".mp4","_trimmed.mp4")  # 截取后文件路径
    trim_audio_ffmpeg(input_audio_path, trimmed_audio_path, start_time=0, duration=3)

    # Step 2: 编码截取后的视频
    base64_audio = encode_audio(trimmed_audio_path)

    # Step 3: 发送分析请求
    completion = client.chat.completions.create(
        model="qwen-omni-turbo",
        messages=[
            {
                "role": "system",
                "content": [
                    {"type": "text", "text": "你是一个专业的视频情感分析助手，请用明确格式回答，包含具体百分比。"}],
            },
            {
                "role": "user",
                "content": [
                    {
                        "type": "video_url",
                        "video_url": {"url": f"data:;base64,{base64_audio}"},
                    },
                    {"type": "text",
                     "text": "分析这段视频的情感构成并总结视频内容类别，情感构成请用以下格式回答：情感名称（百分比%），至少三个及以上感情，视频类别从快乐，射击，休闲三个标签中任意选两个"},
                ],
            },
        ],

#        modalities=["text"],
        stream=True,
        stream_options={"include_usage": True},
    )

    # Step 4: 收集完整响应
    full_text = ""
    for chunk in completion:
        if chunk.choices and chunk.choices[0].delta.content:
            chunk_content = chunk.choices[0].delta.content
            full_text += chunk_content

    # Step 5: 解析并可视化
    emotion_data = parse_emotion_percentages(full_text)

    if emotion_data:

#            print("\n🎭 检测到以下情感分布：")
#            for emotion, percent in emotion_data.items():
#                print(f"- {emotion}: {percent * 100:.1f}%")

            plot_emotion_pie(emotion_data)
