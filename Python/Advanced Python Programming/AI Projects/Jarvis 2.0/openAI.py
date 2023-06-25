import os
import openai

openai.api_key = os.getenv("OpenAI_APIKEY_JarvisAI")

# print(openai.Model.list())

response = openai.Completion.create(
  model="text-curie-001",
  prompt="Hello AI",
  temperature=1,
  max_tokens=2,
  top_p=1,
  frequency_penalty=0,
  presence_penalty=0
)

print(response)