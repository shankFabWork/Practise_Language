# import pyautogui
# pyautogui.scroll(-1000)

def escape_function():
    # pyautogui.press('esc')
    print("2ads")

import threading
timer = threading.Timer(5.0, escape_function)
timer.start()
