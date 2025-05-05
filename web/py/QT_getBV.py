# -*- coding: utf-8 -*-
import csv
import pprint
import random
import sys
from datetime import datetime

import requests
import hashlib
import re
import time
import json
# ffmpeg合并
import subprocess
import os

#from openai import OpenAI
#import urllibs
from urllib import parse


# 存储路径
path = '../web/videos/'

# 推荐信息
url_recommend = 'https://api.bilibili.com/x/web-interface/wbi/index/top/feed/rcmd?web_location=1430650&y_num=4&fresh_type=3&feed_version=V8&fresh_idx_1h=1&fetch_row=1&fresh_idx=1&brush=0&homepage_ver=1&ps=10&last_y_num=4&screen=1120-746&seo_info=&last_showlist=av_114324597244932,av_114329529682749,av_114241063359659,av_114335401645594,av_114334411785316,av_114267957237971,ad_n_5614_114120032519738,av_n_114323171054516,av_n_114322466409440,av_n_114319379400008&last_clicklist=av_114324597244932&uniq_id=709609741408&w_rid=2d39fe49b7cb1f8dcc9989ca3261f546&wts=1744697984'
cookie = "enable_web_push=DISABLE; buvid4=A54574B0-B03F-0958-301C-6FBE84FE908097657-024011214-1KGS5TexHYK0KcKd50nxBA%3D%3D; header_theme_version=CLOSE; rpdid=|(m~RJJulkR0J'u~uuu|)kkJ; buvid_fp_plain=undefined; FEED_LIVE_VERSION=V_WATCHLATER_PIP_WINDOW3; CURRENT_BLACKGAP=0; LIVE_BUVID=AUTO4917255359062857; fingerprint=9c97f88097a0b35c8edb128d5ba15b4d; buvid_fp=9c97f88097a0b35c8edb128d5ba15b4d; DedeUserID=3546776344725904; DedeUserID__ckMd5=dcf3599a48a9126f; match_float_version=ENABLE; hit-dyn-v2=1; _uuid=5324D781-E65F-BF73-C2310-810381B49109C190442infoc; buvid3=DD51F05B-E097-3E53-E9C2-90D7DF141D1128579infoc; b_nut=1736747528; PVID=5; CURRENT_QUALITY=80; enable_feed_channel=ENABLE; share_source_origin=copy_web; bsource=search_bing; bili_ticket=eyJhbGciOiJIUzI1NiIsImtpZCI6InMwMyIsInR5cCI6IkpXVCJ9.eyJleHAiOjE3NDQ5NDIxODYsImlhdCI6MTc0NDY4MjkyNiwicGx0IjotMX0.P9grSMJjp9NtYBLq7ENOpBLt4HYza3oQbVn8bHRK5aI; bili_ticket_expires=1744942126; SESSDATA=c9d4e7c8%2C1760234987%2Cfea0d%2A41CjBsC9uMTpntvaNyY_dwCAaNj0tF-atGZfuSmn4zzLTmWYxitWfOJ-D7N_KUzMsSHu8SVndwT2dEb1hjWGozcm9tN3BXTDY2aHFXYnlhS1ZBb1NobHBsR0hkeFVZSWFSa3hPRE9oWnVnOFkxZGZ3ZUlWMWI5M2lnTWQ5R1NNM1d3V3hRQmpXd1NRIIEC; bili_jct=bcf97d3fbff7c52734ea4bad3af0abbf; sid=6izvfb9r; bp_t_offset_3546776344725904=1055953791741853696; b_lsid=C845E10C2_1963814C389; CURRENT_FNVAL=4048; home_feed_column=4; browser_resolution=1120-746"
user_agent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/133.0.0.0 Safari/537.36 Edg/133.0.0.0"
header = {
    "Cookie": cookie,
    "User-Agent": user_agent,
    # 视频下载用
    "Referer": "https://www.bilibili.com/"
}

aa=os.path.abspath('../web/csv/watch_record.csv')
print("尝试打开文件：", aa)
watch_record=list(list(csv.reader(open(aa, 'r', encoding='utf-8'))))



# initial
class OnlineVideoInfo:
    def __init__(self):
        self.path = path
        self.name = ""
        self.tags = []
        self.emotion=0
        self.keywords=[]
        self.types = ['', '']
        self.duration = 0

        # html_title,html_video,html_audio,html_cover,tags
        self.isDownloaded = 0
        self.uri = ""
        self.sources = []
        self.rank=0
        self.comments = []
        self.datetime = 0

# url等->视频列表
def getRecommendVideoList(url, header):
    result = requests.get(url=url, headers=header)
    json_list = result.json()
    result.close()
    video_list = [i for i in json_list['data']['item'] if i["uri"] != '' and i["duration"] <= 1000]
    return video_list


# 视频content->资源链接
def getVideo_Source(text_video):
    html_title = re.findall('"title":"(.*?)","pubdate":', text_video)[0].replace(' ', '_')
    html_cover = re.findall('pic":"(.*?)","title"', text_video)[0].encode('utf-8').decode('unicode_escape')

    # 文件名
    html_title = re.sub(r'[\\/:*?"<>|]', '_', html_title)
    tags = re.findall(f'class="tag-link">(.*?)</a>', text_video)

    response = requests.get(url=html_cover, headers=header)
    cover_content = response.content
    response.close()

    with open(f"{path}{html_title}.jpg", mode="wb") as file_cover:
        file_cover.write(cover_content)

    new_video = OnlineVideoInfo()
    new_video.name = html_title
    new_video.tags = tags

    return new_video


'''
def getKIMI(order):
    client = OpenAI(
        api_key="sk-3IaBSBmIqZhvOdvz54D1bbc6nHR1rnjlJIcdZzZsxAKlyIPE",
        base_url="https://api.moonshot.cn/v1",
    )
    completion = client.chat.completions.create(
        model="moonshot-v1-8k",
        messages=[
            {"role": "system",
             "content": "listen,"},
            {"role": "user",
             "content": order}
        ],
        temperature=0.3,
    )
    output = completion.choices[0].message.content
    return output

'''

def getVideo_LIST():
    print("\n推荐列表:")
    video_list = getRecommendVideoList(url_recommend, header)

    new_video_list = []
    for video in video_list:
        try:
            uri = video["uri"]
            print(f"\n\n{video_list.index(video)}\t{video["title"]}\n{uri}")
            response = requests.get(url=uri, headers=header)
            text_video = response.text
            response.close()

            new_video = getVideo_Source(text_video)
            # gbk deteck
            with open('123.csv', 'a', newline='') as file:
                writer = csv.writer(file)
                writer.writerow([new_video.name, ' '.join(new_video.tags)])

            new_video.uri = uri
            new_video.duration = video["duration"]

            new_video_list.append(new_video)

            time.sleep(1)
        except Exception as e:
            print(f"ERROR:{video["title"]} in video_list , except:", e)


    return new_video_list




'''
def getVideo_TYPED(new_video_list):
    with open('order_type.txt', "r", encoding='utf-8') as order:
        output = getKIMI(
            f"{order.read()}\n{[f'{new_video_list.index(n)} {n.name} {' '.join(n.tags)}' for n in new_video_list]}")
        temp = output.split('\n')

        type_0 = ['时事国际', '新闻发现', '科普科技', '生态环境', '生活体验', '历史政治', '社会经济', '游戏体育',
                  '美食出行', '影视动画', '艺术音乐', '热梗恶搞', '探险故事', '其他']
        type_1 = ['讲解议论', '记录拍摄', '集锦剪辑', '搞笑娱乐', '教程攻略', '表演创作', '报道访谈', '其他']
        wh = [i.split(' ')[1:] for i in temp]
        for n in new_video_list:
            # 格式化输出
            i = new_video_list.index(n)
            if wh[i][0] not in type_0 or wh[i][1] not in type_1:
                new_video_list.remove(n)
            n.types = wh[i]

'''
'''
def getVideo_EMOTION_KEYWORD(new_video_list):
    with open('order_keyword.txt', "r", encoding='utf-8') as order:
        output = getKIMI(f"{order.read()}\n{[f'{new_video_list.index(n)} {n.name} {' '.join(n.tags)}' for n in new_video_list]}")
        temp = output.split('\n')

        wh = [i.split(' ')[1:] for i in temp]
        for n in new_video_list:
            i=new_video_list.index(n)
            n.emotion=wh[i][0]
            n.keywords=[i for i in wh[i][1:] if len(i)>=2]

    return wh
'''
# oid,wts --> w_rid --> 评论API
# 与getVideoComment配合用
def getWrid(oid, wts):
    # y='mode=3&oid=114107181171696&pagination_str=%7B%22offset%22%3A%22%22%7D&plat=1&seek_rpid=&type=1&web_location=1315875&wts=1741167119'
    en = [
        'mode=3',
        f'oid={oid}',
        'pagination_str=%7B%22offset%22%3A%22%22%7D',
        'plat=1',
        'seek_rpid=',
        'type=1',
        'web_location=1315875',
        f'wts={wts}'
    ]
    a = 'ea1db124af3c7062474693fa704f4ff8'
    y = '&'.join(en)
    x = y + a
    MD5 = hashlib.md5()
    MD5.update(x.encode('utf-8'))
    w_rid = MD5.hexdigest()
    return w_rid


# 视频content -> (oid,wts -> w_rid -> 评论API) ->获取
def getVideo_Comment(text_video):
    pattern_oid = r'"aid":s*(\d+)'
    oid = re.findall(pattern_oid, text_video)[0]
    wts = int(time.time())
    w_rid = getWrid(oid, wts)
    print("oid:", oid)
    print("wts:", wts)
    print("w_rid:", w_rid)

    # 评论首页
    url_comment = f"https://api.bilibili.com/x/v2/reply/wbi/main?oid={oid}&type=1&mode=3&pagination_str=%7B%22offset%22:%22%22%7D&plat=1&seek_rpid=&web_location=1315875&w_rid={w_rid}&wts={wts}"
    response = requests.get(url=url_comment, headers=header)
    json_comment = response.json()
    response.close()
    # cursor=json_comment["data"]["cursor"]
    # num_comments=cursor["all_count"]
    comments = []
    for reply in json_comment["data"]["replies"]:
        # member=reply["member"]
        # m_name=member["uname"]
        content = reply["content"]
        c_message = content["message"]
        comments.append(c_message)
    return comments


def getVideo_SAVED(new_video_list, csvfile_name):
    le=0
    with open(csvfile_name, 'r', newline='') as file:
        temp=list(csv.reader(file))
        le=len(temp)
    with open(csvfile_name, 'a', newline='') as file:
        writer=csv.writer(file)
        for n in new_video_list:
            i=new_video_list.index(n)
            a=[le+i,  n.name,     ' '.join(n.tags),
               f'{n.emotion}',' '.join(n.keywords),n.types[0],n.types[1],
               f'{n.duration}','0',n.uri,'0','0','0','0','0']
            writer.writerow(a)
            i+=1
            print(a)


def getVideo_DOWNLOADED_COMMENTS(vname, uri):
    response = requests.get(url=uri, headers=header)
    text_video = response.text
    response.close()

    links_video = re.findall('<script>window.__playinfo__=(.*?)</script>', text_video)[0]
    video_json = json.loads(links_video)

    # 资源链接
    html_audio = video_json["data"]["dash"]["audio"][0]["baseUrl"]
    html_video = video_json["data"]["dash"]["video"][0]["baseUrl"]

    print(html_video, '\n', html_audio)

    error_step = 0
    try:
        time.sleep(1)
        response = requests.get(url=html_video, headers=header)
        video_content = response.content
        response.close()
        error_step = 1

        time.sleep(1)
        response_1 = requests.get(url=html_audio, headers=header)
        audio_content = response_1.content
        response_1.close()
        error_step = 2


        print("尝试打开文件：", os.path.abspath(f"{path}{vname}_t.mp4"))

        with open(f"{path}{vname}_t.mp4", mode="wb") as file_video:
            file_video.write(video_content)
            error_step = 3
        with open(f"{path}{vname}_t.mp3", mode="wb") as file_audio:
            file_audio.write(audio_content)
            error_step = 4
        # 合并
        command = f"ffmpeg -i {path}{vname}_t.mp4 -i {path}{vname}_t.mp3 -vcodec copy -acodec copy {path}{vname}.mp4"
        subprocess.run(command, check=True)
        error_step = 5

        # stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        os.remove(f"{path}{vname}_t.mp4")
        os.remove(f"{path}{vname}_t.mp3")
        error_step = 6

        comments = getVideo_Comment(text_video)
        error_step = 8
        return True, comments

        # 记录标签
    except Exception as e:
        if os.path.exists(f"{path}{vname}_t.mp4"):
            os.remove(f"{path}{vname}_t.mp4")
        if os.path.exists(f"{path}{vname}_t.mp3"):
            os.remove(f"{path}{vname}_t.mp3")

        print(e, ' \nFailed to Download ', vname, '.mp4 when error_step =', error_step)
        return False, []




def getVideo_Rank_DTime():
    #外界:frame，即一个csv.reader，其表头有Rank、DateTime，其余行缺失此二信息。
    #过程:生成addInfo_csv用于丰富frame，并使用csv.writer存储到RCMDLIST_TEST.csv

    #生成评分信息及其数量
    addInfo_csv=[[0 for j in range(2)] for i in range(200)]
    num_addInfo=0

    while num_addInfo<200:
        day = random.randint(1, 10)
        user_diet=random.random()*0.8
        # 80%左右的概率集中在十个小时
        if random.random() < user_diet:
            hour = random.randint(0,9)
            if hour<3:
                hour=hour+8
            elif hour<6:
                hour=hour+11
            else :
                hour=(hour+17)%24
        else:  # 20%左右概率白天随机
            hour = random.randint(8, 23)

        minute = random.randint(0, 59)
        second = random.randint(0, 59)


        continue_to_watch=random.randint(1,4)
        for con in range( continue_to_watch ):
            specific_time = datetime(2025, 3, day, hour, minute, second)
            rating = random.randint(1,5)

            #循环体
            addInfo_csv[num_addInfo]=[rating,specific_time]
            num_addInfo+=1

            minute=minute+random.randint(2,4)
            hour=(hour+minute//60)%60
            minute=minute%60
            second=random.randint(0,59)

    addInfo_csv=sorted(addInfo_csv,key=lambda x: x[1])

    with open('recommend_list.csv','a',encoding='utf-8',newline='') as file:
        writer = csv.writer(file)
        i=0
        for f in watch_record:
            if i==0:
                writer.writerow(f)
            else :
                l=list(f)
                l+=addInfo_csv[i]
                writer.writerow(l)
            i+=1


def getCSV_Re_ID(csvfile_name):
    watch_record=csv.reader(open(csvfile_name, 'r', newline=''))
    watch_record=list(watch_record)
    new_f=[[] for i in range(len(watch_record))]
    i=0
    for f in watch_record:
        temp_f=list(f)
        if i!=0:
            temp_f[0]=i
        i+=1
        print(temp_f)
        new_f[i-1]=temp_f
    print(new_f)

    writer=csv.writer(open('reID_'+csvfile_name,'w',newline=''))
    writer.writerows(new_f)


def getCSV_ADDVIDEOS(csvfile_name):
    l = getVideo_LIST()
    getVideo_TYPED(l)
    getVideo_EMOTION_KEYWORD(l)
    for i in l:
        print(l.index(i), i.name)

    getVideo_SAVED(l,csvfile_name)

def getVideo_SEARCH_Result(enter):
    enter=repr(enter)[1:-1]
    new_txt = urllib.parse.quote(enter)
    new_txt=new_txt.replace('%20','+')
    url = 'https://search.bilibili.com/all?keyword='+new_txt+'&search_source=1'

    response=requests.get(url=url,headers=header)
    text=response.text
    response.close()

    #print(text)

    raw_videoinfos = re.findall('bili-video-card__wrap(.*?)bili-video-card__mask', text)
    videoinfos=[[] for i in range(len(raw_videoinfos))]
    i=0
    for v in raw_videoinfos:
     #   print(v)
        covers=re.findall('srcset="//(.*?)" type="image/avif',v)
        titles=re.findall('alt="(.*?)" loading=',v)
        urls=re.findall('href="//(.*?)" class=',v)

        cover=covers[0] if len(covers)>0 else ''
        title=titles[0].replace(' ','_') if len(titles)>0 else ''
        title=re.sub(r'[\\/:*?"<>|]', '_', title) if title!='' else ''
        url="https://"+urls[0] if len(urls)>0 else ''

        if cover and title and url:
            videoinfos[i]=[title,cover,url]
            i+=1


    with open(enter+'.csv','w',newline='',encoding='utf-8') as file:
        writer=csv.writer(file)
        writer.writerows(videoinfos)


if __name__ == '__main__':

    #getCSV_ADDVIDEOS('recommend_list.csv')

    #getVideo_SEARCH_Result('look in my eyes')

    ''''''
    arg1 = sys.argv[1]
    arg2=sys.argv[2] if len(sys.argv)>2 else ''
    if arg1== 'download':
        getVideo_DOWNLOADED_COMMENTS(path,'temp',arg2)
    elif arg1=='search':
        getVideo_SEARCH_Result(arg2.replace(" ",""))
    sys.exit()



