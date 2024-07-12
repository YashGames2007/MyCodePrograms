from OpenAI.chat_writer import Chat
from OpenAI import openAI_API_Request as openai_request
from src.triggers import using_triggers
from src.resources import authentication_rights
from src.toolkit import check_pattern, replace_all, print_and_return


class OpenAI:
    def __init__(self, model: str = "gpt-3.5-turbo") -> None:
        self.chat = list()
        self.model = model
        self.seed = 0

    def open(self, query: str) -> str:
        if check_pattern(query, "{} ai", [using_triggers]) == []:
            return False

        self.chat.extend(
            [
                {"role": "user", "content": query.replace(" by ai ", " ")},
                openai_request.getMessage(self.chat, model=self.model),
            ]
        )

        response = replace_all(self.chat[-1]["content"].lower(), authentication_rights)
        self.seed = Chat().writeChat(self.chat, self.model)
        return print_and_return(response)

    def __del__(self) -> None:
        print(f"Current Chat Saved at: {self.seed}")
