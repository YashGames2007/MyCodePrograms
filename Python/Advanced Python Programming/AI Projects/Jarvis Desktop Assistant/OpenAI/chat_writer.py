import json
import os
from datetime import datetime

class Chat:
    path = 'E:\\Programming files\\Code\\Python\\Advanced Python Programming\\AI Projects\\Jarvis Desktop Assistant\\OpenAI\\'

    def __init__(self) -> None:
        if not os.path.exists(self.path):
            os.makedirs(self.path)

        time = datetime.now()
        self.seed = time.strftime("%d %b %Y  %I-%M-%S %p")

    def writeResponse(self, response:list, model:str) -> str:
        time = datetime.now()
        seed = time.strftime("%d %b %Y  %I-%M-%S %p")
        dir_path = os.path.join(self.path, f"Response History [{model}]\\")
        if not os.path.exists(dir_path):
            os.makedirs(dir_path)
        response_file = os.path.join(dir_path, f"Response [{seed}].json")
        with open(response_file, 'w') as rFile:
            json.dump(response, rFile, indent=4)
        
        return f"[{seed}]"

    def writeChat(self, chat:list, model:str) -> str:
        dir_path = os.path.join(self.path, f"Chat History [{model}]\\")
        if not os.path.exists(dir_path):
            os.makedirs(dir_path)
        chat_file = os.path.join(dir_path, f"Chat [{self.seed}].json")
        with open(chat_file, 'w') as cFile:
            json.dump(chat, cFile, indent=4)
        return f"[{self.seed}]"


    def read(self, file_name:str) -> list:
        data = []
        with open(file_name, 'r') as file:
            data = json.load(file)
        return data
    
    def read(self, count:int=1) -> list:
        lst = sorted(os.listdir(self.path), reverse=True)
        print(lst)
        return lst[:count]