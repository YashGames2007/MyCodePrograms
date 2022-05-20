import pyautogui # pip install pyautogui
from PIL import Image, ImageGrab # pip install pillow
# from numpy import asarray
import time

def hit(key):
    pyautogui.keyDown(key)
    return

def isCollide(data):
    # Draw the rectangle for birds
    for i in range(375, 425):
        for j in range(410, 500):
            if data[i, j] < 100:
                hit("up")
                return

    for i in range(450, 500):
        for j in range(350, 410):
            if data[i, j] < 100:
                hit("down")
                return
    return

if __name__ == "__main__":
    print("Hey.. Dino game about to start in 3 seconds")
    time.sleep(2)
    # hit('up') 

    while True:
        image = ImageGrab.grab().convert('L')  
        data = image.load()
        isCollide(data)
            
        # print(asarray(image))
        
        # Draw the rectangle for cactus
        for i in range(375, 425):     #Horizontal
            for j in range(410, 450): #Vertical
                data[i, j] = 0
        
        # Draw the rectangle for birds
        for i in range(375, 400):     #Horizontal
            for j in range(350, 410): #Vertical
                data[i, j] = 171

        image.show()
        break