import pandas as pd
from googleapiclient.discovery import build
from datetime import datetime, timezone
import time

# API 키와 동영상 ID
api_key = 'AIzaSyAbxn1WaqgTTeDChIPKTO5M-BEhHMlE79E'
video_id = 'U7V2hSIXsvU'

# YouTube API 객체 생성
api_obj = build('youtube', 'v3', developerKey=api_key)

# 댓글을 저장할 리스트
comments = []

# UTC 시간을 현지 시간으로 변환하는 함수
def convert_utc_to_local(utc_time_str):
    utc_time = datetime.strptime(utc_time_str, '%Y-%m-%dT%H:%M:%SZ')  # UTC 시간 파싱
    local_time = utc_time.replace(tzinfo=timezone.utc).astimezone()  # 현지 시간대로 변환
    return local_time

while True:
    # 최신 댓글 100개까지 조회
    response = api_obj.commentThreads().list(
        part='snippet,replies',
        videoId=video_id,
        maxResults=100
    ).execute()

    # 댓글 수집 및 처리
    for item in response['items']:
        comment = item['snippet']['topLevelComment']['snippet']
        # 날짜를 현지 시간으로 변환
        local_time = convert_utc_to_local(comment['publishedAt'])
        if local_time.date() == datetime.now().date():
            comments.append({
                'comment': comment['textDisplay'],
                'author': comment['authorDisplayName'],
                'date': local_time.strftime('%Y-%m-%d %H:%M:%S'),  # 원하는 형식으로 변환
                'timestamp': local_time  # 비교를 위해 원본 시간 저장
            })

        # 답글 처리 (만약 있을 경우)
        if item['snippet']['totalReplyCount'] > 0:
            for reply_item in item['replies']['comments']:
                reply = reply_item['snippet']
                local_time = convert_utc_to_local(reply['publishedAt'])
                # 24일에 작성된 답글만 추가
                if local_time.date() == datetime.now().date():
                    comments.append({
                        'comment': reply['textDisplay'],
                        'author': reply['authorDisplayName'],
                        'date': local_time.strftime('%Y-%m-%d %H:%M:%S'),
                        'timestamp': local_time  # 비교를 위해 원본 시간 저장
                    })

    # 댓글을 최신순으로 정렬
    comments.sort(key=lambda x: x['timestamp'], reverse=True)

    # 인접한 댓글 간의 시간 차이를 계산
    time_diffs = []
    for i in range(len(comments) - 1):
        time_diff = comments[i]['timestamp'] - comments[i + 1]['timestamp']
        diff_seconds = int(time_diff.total_seconds())
        time_diffs.append(diff_seconds)

    # 댓글에 시간 차이 추가
    for i in range(len(comments) - 1):
        hours, remainder = divmod(time_diffs[i], 3600)  # 시 계산
        minutes, seconds = divmod(remainder, 60)       # 분과 초 계산
        comments[i]['time_difference'] = f"{hours}시간 {minutes}분 {seconds}초"

    # 마지막 댓글에는 시간 차이가 없으므로 None으로 설정
    comments[-1]['time_difference'] = None

    # 엑셀 파일로 저장
    df = pd.DataFrame(comments)
    df.to_excel('results.xlsx', index=False, 
               header=['댓글 내용', '아이디', '날짜', '시간 차이'], 
               columns=['comment', 'author', 'date', 'time_difference'])

    print("현재 저장된 댓글 수:", len(comments))
    for comment in comments:
        time_diff = comment['time_difference'] if comment['time_difference'] else 'N/A'
        print(f"댓글: '{comment['comment']}' (작성자: {comment['author']}) - 시간 차이: {time_diff}")

    # 30초 이상의 시간 차이가 있는지 확인
    if all(diff <= 3599 for diff in time_diffs):
        print("모든 댓글 간의 시간 차이가 1시간 미만입니다. 댓글을 다시 받아옵니다.")
        time.sleep(1200)  # 50분 대기 후 댓글을 다시 가져옴
        comments.clear()  # 댓글 초기화
    else:
        print("댓글 간의 시간 차이가 1시간을 넘었습니다. 종료합니다.")
        break

