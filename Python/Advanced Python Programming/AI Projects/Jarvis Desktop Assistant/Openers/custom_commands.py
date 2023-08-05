from requests import get
import wikipedia

class Custom:
    def __init__(self) -> None:
        pass
    def open(self, query:str) -> str|bool:
        if "show ip address" in query:
            ip = get('https://api.ipify.org').text
            print(f"IP: {ip}")
            return f"Your IP Address is {ip}."
        if "wikipedia" in query:
            query = query.replace("wikipedia", "").replace("open", "").replace("show", "").replace("me", "")
            wiki = wikipedia.summary(query, sentences=3)
            print(f"According to wikipedia, {wiki}")
            return f"According to wikipedia, {wiki}"

        return False