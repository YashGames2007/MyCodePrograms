import os
import subprocess
import re

"""
ADDITIONS:

Skype
MS Store
Quick Assist
Snipping Tool
Sticky Notes
My phone
PC Health Check
"""

apps = {
    "file explorer": ["file explorer", "explorer"],
    "calculator|calc": ["calculator", "calc"],
    "word|ms word|microsoft word": ["ms word", "C:\\Users\\SAI\\OFFICE\\root\\Office16\\WINWORD.EXE"],
    "camera": ["your camera", "C:\\Program Files\\WindowsApps\\Microsoft.WindowsCamera_2023.2305.4.0_x64__8wekyb3d8bbwe\\WindowsCamera.exe"],
    "excel": ["ms excel", "C:\\Users\\SAI\\OFFICE\\root\\Office16\\EXCEL.EXE"],
    "powerpoint": ["ms powerpoint", "C:\\Users\\SAI\\OFFICE\\root\\Office16\\POWERPNT.EXE"],
    "onenote": ["ms onenote", "C:\\Users\\SAI\\OFFICE\\root\\Office16\\ONENOTE.EXE"],
    "onedrive": ["local onedrive", "C:\\Users\\SAI\\AppData\\Local\\Microsoft\\OneDrive\\OneDrive.exe"],
    "clock": ["clock", "C:\\Program Files\\WindowsApps\\Microsoft.WindowsAlarms_11.2304.0.0_x64__8wekyb3d8bbwe\\Time.exe"],
    "task manager": ["task manager", "taskmgr"],
    "cmd": ["cmd", "C:\\WINDOWS\\system32\\cmd.exe"],
    "command prompt": ["cmd", "C:\\WINDOWS\\system32\\cmd.exe"],
    "control panel": ["control panel", "C:\\Windows\\System32\\control.exe"],
    "wordpad": ["wordpad", "C:\\Program Files\\Windows NT\\Accessories\\wordpad.exe"],
    "pc manager": ["pc manager", "C:\\Program Files\\Microsoft PC Manager\\MSPCManager.exe"],
    "vs code": ["vs code", "C:\\Users\\SAI\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe"],
    "browser": ["microsoft edge", "C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe"],
    "microsoft edge": ["ms edge", "C:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe"],
    "visual studio code": ["vs code", "C:\\Users\\SAI\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe"],
    "paint 3d": ["paint 3d", "ms-paint:"],
    "paint": ["paint", "C:\\Users\\SAI\\AppData\\Local\\Microsoft\\WindowsApps\\Microsoft.Paint_8wekyb3d8bbwe\\mspaint.exe"],
    "powershell": ["powershell", "C:\\Users\\SAI\\AppData\\Local\\Microsoft\\WindowsApps\\PowerShell-7.2.7-win-x64\\pwsh.exe"],
    "terminal": ["terminal", "C:\\Users\\SAI\\AppData\\Local\\Microsoft\\WindowsApps\\Microsoft.WindowsTerminal_8wekyb3d8bbwe\\wt.exe"],
    "notepad": ["notepad", "C:\\Program Files\\WindowsApps\\Microsoft.WindowsNotepad_11.2305.18.0_x64__8wekyb3d8bbwe\\Notepad\\Notepad.exe"],
}

folders = {
    "c": ["c drive", "C:\\"],
    "e": ["e drive", "E:\\"],
    "downloads": ["downloads folder", "C:\\Users\\SAI\\Downloads\\"],
}

class app:
    def open(self, query: str) -> bool:
        """

        """
        for app, location in apps.items():
            if "open " in query and re.search(app, query) != None:
                os.startfile(location[1])
                return f"opening {location[0]}"
        
        for folder, path in folders.items():
            if f"open {folder} folder" in query or f"open {folder} drive" in query or f"open {folder} directory" in query:
                os.startfile(path[1])
                return f"opening {path[0]}"
        
        if "open setting" in query:
            os.system("start ms-settings")
            return "opening settings"
        elif "open recycle bin" in query:
            subprocess.Popen(["explorer", "shell:RecycleBinFolder"])
            return "opening recycle bin"
        return False
