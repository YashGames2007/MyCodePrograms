import pyautogui
import time
def stringTyper(string):
    time.sleep(2)
    pyautogui.keyDown("ctrl")
    pyautogui.keyDown("j")
    pyautogui.keyUp("ctrl")
    pyautogui.keyDown("ctrl + j")
    for i in range(len(string)):
        pyautogui.keyDown(string[i])

try:
    num = int(input("Type the number that you have table of :- "))
except Exception as e:
    print("Invalid Number !")
    num = int(input("Type the number that you have table of :- ")) 

stringTyper(f'*** The Table of {num} ***\n\n{num} one za {num * 1}\n{num} two za {num * 2}\n{num} three za {num * 3}\n{num} four za {num * 4}\n{num} five za {num * 5}\n{num} six za {num * 6}\n{num} seven za {num * 7}\n{num} eight za {num * 8}\n{num} nine za {num * 9}\n{num} ten za {num * 10}\n')
# time.sleep(7)
# for i in range(33, 101):
#     stringTyper(f"{i} : [blockX[0], blockY[0]],")
#     pyautogui.keyDown("Enter")