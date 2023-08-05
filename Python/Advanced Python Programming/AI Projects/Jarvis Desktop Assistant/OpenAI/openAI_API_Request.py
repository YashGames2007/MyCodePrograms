import os
import openai
from OpenAI.chat_writer import Chat

openai.api_key = os.getenv("Jarvis_API_KEY")
chat = Chat()

def getResponse(messages:list, temperature=1, max_tokens=256,model="gpt-3.5-turbo") -> dict:

    response = openai.ChatCompletion.create(
    model=model,
    messages=messages,
    temperature=temperature,
    max_tokens=max_tokens,
    top_p=1,
    frequency_penalty=0,
    presence_penalty=0
    )
    chat.writeResponse(response, model)
    return response

def getMessage(messages:list, temperature=1, max_tokens=256,model="gpt-3.5-turbo") -> dict:
    return dict(getResponse(messages, temperature, max_tokens, model)["choices"][0]["message"])

"""

{  
  "id": "chatcmpl-7j8ratIBsOWBRTyuIwlKwkX5txJtA",
  "object": "chat.completion",
  "created": 1690993186,
  "model": "gpt-3.5-turbo-0613",
  "choices": [
    {
      "index": 0,
      "message": {
        "role": "assistant",
        "content": "To close specific tabs opened in a browser using Python, you can make use of the Selenium library. Below is an example that demonstrates how to close specific tabs in Google Chrome:\n\nFirst, make sure you have the Selenium library installed. You can install it using the following command:\n\n```python\npip install selenium\n```\n\nNext, use the following code to close specific tabs:\n\n```python\nfrom selenium import webdriver\nfrom selenium.webdriver.common.keys import Keys\n\n# Open the browser and navigate to a website\ndriver = webdriver.Chrome()\ndriver.get('https://www.example.com')\n\n# Open additional tabs in the browser\ndriver.find_element_by_tag_name('body').send_keys(Keys.CONTROL + 't')\ndriver.get('https://www.google.com')\n\ndriver.find_element_by_tag_name('body').send_keys(Keys.CONTROL + 't')\ndriver.get('https://www.python.org')\n\n# Switch to the desired tab and close it\ndriver.switch_to.window(driver.window_handles[1])\ndriver.close()\n\n# Switch to the desired tab and close it\ndriver.switch_to.window(driver.window_handles[0])\ndriver.close()\n```\n\nIn the above code, we first open the browser and navigate to a website (`https://www.example.com`). Then, we open additional tabs using the `"
      },
      "finish_reason": "length"
    }
  ],
  "usage": {
    "prompt_tokens": 18,
    "completion_tokens": 256,
    "total_tokens": 274
  }
}


"""