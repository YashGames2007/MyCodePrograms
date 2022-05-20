import pyttsx3
import speech_recognition as sr
import datetime
import wikipedia
import webbrowser
import os
import smtplib

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
# print(voices[0].id)
engine.setProperty('voice', voices[0].id)

def speak (audio):
    engine.say(audio)
    engine.runAndWait()

def wishMe():
    hour = int(datetime.datetime.now().hour)

    if(hour < 6):
        speak("Good Night Sir!")
    elif(hour >= 6 and hour < 12):
        speak("Good Morning Sir!")
    elif(hour >= 12 and hour < 18):
        speak("Good Afternoon Sir!")
    elif(hour >= 18):
        speak("Good Evining Sir!")
    
    speak("I am Jarvis Your Dekstop Assistant.")
    speak("Please Say How Can I Help You.")

def takeCommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        r.energy_threshold = 500
        r.pause_threshold = 1
        audio = r.listen(source)
        print("Ok!")
        try:
            print("Recognizing...")
            query = r.recognize_google(audio, language='en-us')
            print(f"User said: {query}\n")
            speak(f"Ok! You Said {query}")
        except Exception as e:
            print("Say that again please...")
            return "None"
        return query

if __name__ == '__main__':
    wishMe()
    query = takeCommand().lower()
    if ("open youtube" in query):
        # query = query.replace("open ", "")
        webbrowser.open("youtube.com")
    elif ():
        pass
    else :
        pass
