import sys
import pyttsx3
import speech_recognition as speech
import datetime

# import wikipedia
# import smtplib

# Library Components
from Openers.web_opener import Web
from Openers.app_opener import App
from Openers.custom_commands import Custom
from Openers.openai_opener import OpenAI
from src.triggers import quitting_triggers
from src.toolkit import check_pattern


class Jarvis:
    engine = pyttsx3.init("sapi5")
    voices = engine.getProperty("voices")
    engine.setProperty("voice", voices[0].id)

    def __init__(self):
        webSearch = Web()
        appSearch = App()
        customSearch = Custom()
        openaiSearch = OpenAI()
        self.query_operators = [webSearch, appSearch, customSearch, openaiSearch]

    def speak(self, audio):
        self.engine.say(audio)
        self.engine.runAndWait()

    def wishMe(self):
        # TODO: Implement DRY
        hour = int(datetime.datetime.now().hour)

        if hour < 6:
            self.speak("Good Night Sir!")
        elif hour >= 6 and hour < 12:
            self.speak("Good Morning Sir!")
        elif hour >= 12 and hour < 18:
            self.speak("Good Afternoon Sir!")
        elif hour >= 18:
            self.speak("Good Evening Sir!")

        self.speak("I am Jarvis Your Desktop Assistant.")

    def takeCommand(self, command: str) -> str:
        # TODO: Make it simple
        self.speak(command)
        mic = speech.Recognizer()
        with speech.Microphone() as source:
            print("Listening...")
            mic.energy_threshold = 3000
            mic.pause_threshold = 1.5
            try:
                audio = mic.listen(source, timeout=3)
                print("Recognizing...")
                query = mic.recognize_google(audio, language="en-in")
                print(f"User said: {query}\n")
            except speech.RequestError as e:
                print("Couldn't Connect to Internet...")
                sys.exit()
            except Exception as e:
                print("Say that again please...")
                return "None"
            return query

    def run(self, command: str = "What can I do for you?"):
        query = self.takeCommand(command).lower()

        for function in self.query_operators:
            working = function.open(query)
            if working:
                self.speak("Okay! " + working)
                return True

        if check_pattern(query, "{}", [quitting_triggers]) != []:
            return False
        if not working:
            return self.run("Sir! I didn't Understood, Say correctly please.")
        return True

    def start(self):
        self.wishMe()
        running = self.run()
        while running:
            running = self.run("Anything else can I do for you sir?")

        self.speak(
            "Thanks for using me sir, Jarvis Turning Off, Good Bye, Have a nice day.!"
        )


if __name__ == "__main__":
    jarvis = Jarvis()
    jarvis.start()
