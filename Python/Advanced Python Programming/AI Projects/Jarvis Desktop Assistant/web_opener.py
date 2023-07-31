import webbrowser

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

"""

websites = {
    "youtube": ["youtube", "https://www.youtube.com/"],
    "whatsapp": ["whatsapp", "https://web.whatsapp.com/"],
    "telegram": ["telegram", "https://web.telegram.org/k/#777000"],
    "stack overflow": ["your stackoverflow", "https://stackoverflow.com/users/17628133/yashgames2007"],
    "docs": ["google docs", "https://docs.google.com/document/u/0/"],
    "sheets": ["google sheets", "https://docs.google.com/spreadsheets/u/0/"],
    "slides": ["google slides", "https://docs.google.com/presentation/u/0/"],
    "google": ["google", "https://www.google.com/"],
    "gdrive": ["google drive", "https://drive.google.com/drive/u/0/my-drive?ths=true"],
    "gmail": ["gmail", "https://mail.google.com/mail/u/0/#inbox"],
    "google drive": ["google drive", "https://drive.google.com/drive/u/0/my-drive?ths=true"],
    "notion": ["notion", "https://www.notion.so/yashgames2007/My-Dashboard-78a391e7ee3f447584f7c4e69d5fd10d"],
    "click up": ["clickup", "https://app.clickup.com/9002068348/home"],
    "whimsical": ["whimsical", "https://whimsical.com/my-files-MX2S26bgNM8xJYwzsWzWDk"],
    "spotify": ["spotify", "https://open.spotify.com/"],
    "chat gpt": ["chat gpt", "https://chat.openai.com/"],
    "bard": ["google bard", "https://bard.google.com/u/1/"], 
    "file converter": ["online file converter", "https://www.online-convert.com/"], 
    "calendar": ["google calendar", "https://calendar.google.com/calendar/u/0/r"],
    "github": ["your github", "https://github.com/YashManojraoBhavsar"],
    "get hub": ["your github", "https://github.com/YashManojraoBhavsar"],
    "forms": ["ms forms", "https://www.office.com/launch/forms?auth=1"],
    "ms office": ["ms office online", "https://www.office.com/?auth=1"],
    "microsoft office": ["ms office online", "https://www.office.com/?auth=1"],
}

webApps = {
    "word": ["ms word", "https://www.office.com/launch/word?auth=1"],
    "excel": ["ms excel", "https://www.office.com/launch/excel?auth=1"],
    "powerpoint": ["ms powerpoint", "https://www.office.com/launch/powerpoint?auth=1"],
    "onedrive": ["onedrive", "https://onedrive.live.com/?WT.mc_id=PROD%5FOL%2DWeb%5FInApp%5FLeftNav%5FFreeOfficeBarOD&ocid=PROD%5FOL%2DWeb%5FInApp%5FLeftNav%5FFreeOfficeBarOD&id=root&cid=E21EFB7D22FEDAA2"],
}


class web:
    browser_path = "C:/Program Files (x86)/Microsoft/Edge/Application/msedge.exe %s"

    def open(self, query: str) -> bool:
        for website, url in websites.items():
            if f"open {website}" in query:
                webbrowser.get(self.browser_path).open(url[1])
                return f"Opening {url[0]}"
        
        if "on the web" in query or "on web" in query or "in browser" in query:
            for website, url in webApps.items():
                if f"open {website}" in query:
                    webbrowser.get(self.browser_path).open(url[1])
                    return f"Opening {url[0]}"

        return False
