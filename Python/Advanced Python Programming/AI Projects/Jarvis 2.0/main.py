import speech_recognition as recognizer
import webbrowser
import win32com.client as speak

class Jarvis_System:
    
    def __init__(self):
        self.speaker = speak.Dispatch("SAPI.SpVoice")
        self.listener = recognizer.Recognizer()
    
    def speak(self, text):
        self.speaker.Speak(text)

    def listen(self):
        with recognizer.Microphone() as source:
            print("Listening...")
            self.listener.energy_threshold = 1500
            self.listener.pause_threshold = 1
            audio_input = self.listener.listen(source)
            print("Ok!")
            try:
                print("Recognizing...")
                query = self.listener.recognize_google(audio_input, language='en-in')
                print(f"User said: {query}\n")
                # self.speak(f"Ok! You Said {query}")
            except Exception as e:
                print("Say that again please...")
                return "None"
            return query
        

class Jarvis_AI:

    def __init__(self):
        self.system = Jarvis_System()
    
    def __call__(self):
        while True:
            self.system.speak("I am Jarvis i am A.I. Talk Something to be tested")
            self.system.listen()



if __name__ == "__main__":
    print("Running...")
    _AI = Jarvis_AI()
    _AI()
        