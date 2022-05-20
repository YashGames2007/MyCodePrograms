import pyautogui
import time
def stringTyper(string):
    # time.sleep(2)
    # pyautogui.keyDown("ctrl")
    # pyautogui.keyDown("j")
    # pyautogui.keyUp("ctrl")
    # pyautogui.keyDown("ctrl + j")
    for i in range(len(string)):
        pyautogui.keyDown(string[i])

time.sleep(5)
for i in range (114):
    time.sleep(2)
    pyautogui.keyDown("F2")
    time.sleep(1)
    stringTyper(f'_Geography Navneet 10th page {i}')
    pyautogui.keyDown("Enter")
    time.sleep(1)
    pyautogui.keyDown("right")