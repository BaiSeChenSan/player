# This Python file uses the following encoding: utf-8

# if __name__ == "__main__":
#     pass
import time
import threading

def compute():
    print("Python thread ID:", threading.current_thread().ident)
    delay_sec = 5  # 设置延时秒数
    print(f"Start {delay_sec}s delay...")
    time.sleep(delay_sec)
    print("Delay completed")
    return 42
