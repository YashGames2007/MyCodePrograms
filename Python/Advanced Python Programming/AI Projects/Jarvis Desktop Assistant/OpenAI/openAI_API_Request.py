import os
import openai
from OpenAI.chat_writer import Chat

openai.api_key = os.getenv("Jarvis_API_KEY")


def _get_response(messages: list, temperature=1, max_tokens=256, model="gpt-3.5-turbo") -> dict:
    response = openai.ChatCompletion.create(
        model=model,
        messages=messages,
        temperature=temperature,
        max_tokens=max_tokens,
        top_p=1,
        frequency_penalty=0,
        presence_penalty=0,
    )
    Chat().writeResponse(response, model)
    return response

def _get_message(messages: list, temperature=1, max_tokens=256, model="gpt-3.5-turbo") -> dict:
    return dict(_get_response(messages, temperature, max_tokens, model)["choices"][0]["message"])