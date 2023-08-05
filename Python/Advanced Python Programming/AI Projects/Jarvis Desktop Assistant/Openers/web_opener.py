import webbrowser
import re

"""
ADDITIONS:

Skype
Loop
Outlook
OneNote
MS Calendar
MS To Do
Sway
Teams

Chrome Web Store
Linked In
Repl It
Google Meet
Zoom Meet
Typing Trainer
Typing Racer

Photoshop
Firefly
More Adobe Tools on the web

Facebook
Instagram
Wikipedia


"""

websites = {
    "youtube|yt": ["youtube", "https://www.youtube.com/"],
    "whatsapp": ["whatsapp", "https://web.whatsapp.com/"],
    "telegram": ["telegram", "https://web.telegram.org/k/#777000"],
    "stack overflow": ["your stackoverflow", "https://stackoverflow.com/users/17628133/yashgames2007"],
    "docs|google docs": ["google docs", "https://docs.google.com/document/u/0/"],
    "sheets|google sheets": ["google sheets", "https://docs.google.com/spreadsheets/u/0/"],
    "slides|google slides": ["google slides", "https://docs.google.com/presentation/u/0/"],
    "google|search": ["google", "https://www.google.com/"],
    "gmail|email|mail": ["gmail", "https://mail.google.com/mail/u/0/#inbox"],
    "google drive|gdrive|g drive": ["google drive", "https://drive.google.com/drive/u/0/my-drive?ths=true"],
    "notion": ["notion", "https://www.notion.so/yashgames2007/My-Dashboard-78a391e7ee3f447584f7c4e69d5fd10d"],
    "click up": ["clickup", "https://app.clickup.com/9002068348/home"],
    "whimsical": ["whimsical", "https://whimsical.com/my-files-MX2S26bgNM8xJYwzsWzWDk"],
    "spotify": ["spotify", "https://open.spotify.com/"],
    "chat gpt|open ai": ["chat gpt", "https://chat.openai.com/"],
    "bard|google bard|google ai": ["google bard", "https://bard.google.com/u/1/"], 
    "file converter|online converter|web converter": ["online file converter", "https://www.online-convert.com/"], 
    "calendar|google calendar|gcal": ["google calendar", "https://calendar.google.com/calendar/u/0/r"],
    "github|get hub": ["your github", "https://github.com/YashManojraoBhavsar"],
    "forms|ms forms": ["ms forms", "https://www.office.com/launch/forms?auth=1"],
    "office|ms office|microsoft office": ["ms office online", "https://www.office.com/?auth=1"],
}

webApps = {
    "word|ms word|microsoft word": ["ms word", "https://www.office.com/launch/word?auth=1"],
    "excel|ms excel|microsoft excel": ["ms excel", "https://www.office.com/launch/excel?auth=1"],
    "powerpoint|ms powerpoint|microsoft powerpoint": ["ms powerpoint", "https://www.office.com/launch/powerpoint?auth=1"],
    "onedrive|ms onedrive|microsoft onedrive": ["onedrive", "https://onedrive.live.com/?WT.mc_id=PROD%5FOL%2DWeb%5FInApp%5FLeftNav%5FFreeOfficeBarOD&ocid=PROD%5FOL%2DWeb%5FInApp%5FLeftNav%5FFreeOfficeBarOD&id=root&cid=E21EFB7D22FEDAA2"],
}

triggers = ["on the web", "online", "in browser", "on web"]

class Web:
    browser_path = "C:/Program Files (x86)/Microsoft/Edge/Application/msedge.exe %s"

    def open(self, query: str) -> str|bool:
        for website, url in websites.items():
            if "open " in query and re.search(website, query) != None:
                webbrowser.get(self.browser_path).open(url[1])
                return f"Opening {url[0]}"
        for trigger in triggers:
            if trigger in query:
                for website, url in webApps.items():
                    if re.search(f"open .{website} {trigger}", query):
                        webbrowser.get(self.browser_path).open(url[1])
                        return f"Opening {url[0]}"
        return False
