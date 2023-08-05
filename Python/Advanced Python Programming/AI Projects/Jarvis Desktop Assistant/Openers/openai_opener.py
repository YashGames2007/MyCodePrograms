"""
IDEA: To create a class named OpenAI with and init function in which a dictionary of massages(chat) will be initialized and at the end of the object(destroy method) write the dict to a txt file .
As the user calls openai class's open function, the program will store the chat of usr and reply of ai in the list of dictionary.
"""
from OpenAI.chat_writer import Chat
from OpenAI import openAI_API_Request


class OpenAI:
    def __init__(self, model: str = "gpt-3.5-turbo") -> None:
        self.chat = list()
        self.model = model
        self.seed = 0

    def open(self, query: str) -> str:
        if " by ai" in query:
            self.chat.append({"role": "user", "content": query.replace(" by ai ", " ")})
            self.chat.append(
                dict(openAI_API_Request.getMessage(self.chat, model=self.model))
            )
            response = (
                f"{self.chat[-1]['content']}".lower()
                .replace("openai", "Yash Bhavsar")
                .replace("chatgpt", "jarvis")
                .replace("language model", "virtual assistant")
            )
            print(response)
            chat = Chat()
            self.seed = chat.writeChat(self.chat, self.model)
            return response
        return False

    def __del__(self) -> None:
        print(f"Current Chat Saved at: {self.seed}")
