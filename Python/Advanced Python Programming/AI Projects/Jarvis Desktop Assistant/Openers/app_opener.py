import os
import subprocess
import re

from src.triggers import dir_triggers, open_triggers, close_triggers, unclosable_triggers
from src.paths import app_paths, folder_paths

class App:
    def open(self, query: str) -> str | bool:
        
        for app, location in app_paths.items():
            for trigger, triggering in open_triggers.items():
                if f"{trigger} " in query and re.search(app, query) != None:
                    os.startfile(location[1])
                    return f"{triggering} {location[0]}"
            
            for trigger, triggering in close_triggers.items():
                if f"{trigger} " in query and re.search(app, query) != None:
                    if location[0] in unclosable_triggers:
                        print(f"Can't {trigger} {location[0]}!")
                        return f"Can't {trigger} {location[0]}!"
                    path = location[1][location[1].rfind("\\") + 1 :]
                    print(path)

                    try:
                        subprocess.run(["taskkill", "/F", "/IM", path], check=True)
                        return f"{triggering} {location[0]}"
                    except subprocess.CalledProcessError as e:
                        return f"can't {trigger} {location[0]}!!!"

        for trigger in dir_triggers:
            if trigger in query:
                for folder, path in folder_paths.items():
                    for _open, _opening in open_triggers.items():
                        if re.search(f"{_open} .{folder} {trigger}", query) != None:
                            os.startfile(path[1])
                            return f"{_opening} {path[0]}"

        for trigger, triggering in open_triggers.items():
            if f"{trigger} " in query:
                if (
                    re.search(
                        f"settings|windows settings|local settings|device settings", query
                    )
                    != None
                ):
                    os.system("start ms-settings:")
                    return f"{triggering} settings"
                elif (
                    re.search(
                        f"recycle bin|windows recycle bin|local recycle bin|device recycle bin",
                        query,
                    )
                    != None
                ):
                    subprocess.Popen(["explorer", "shell:RecycleBinFolder"])
                    return f"{triggering} recycle bin"
        return False
