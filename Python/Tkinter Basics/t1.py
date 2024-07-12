from tkinter import *
from PIL import Image, ImageTk

root = Tk()
root.geometry("700x700")
root.minsize(200, 100)
file = Image.open("Python\Pygame Basic to Advanced\FLAPPY Bird Game\Game_Sprites\logo.png")
img = ImageTk.PhotoImage(file)
label = Label(text="This is a label", 
              bg="blue", 
              fg="white", 
              font="sanserif 19 bold",
              padx=123, pady=123,
              borderwidth=15,
              relief=SUNKEN
            )
label2 = Label(image=img)
label.pack()
label2.pack()

root.title("My GUI with YashGames2007")
root.mainloop()