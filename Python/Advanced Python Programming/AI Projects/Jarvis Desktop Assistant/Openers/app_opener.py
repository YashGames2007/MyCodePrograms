import os
import subprocess

from src.triggers import (
    dir_triggers,
    open_triggers,
    close_triggers,
    ms_triggers,
    unclosable_triggers,
    suffix_triggers,
)
from src.paths import app_paths, ms_app_paths, folder_paths
from src.toolkit import check_pattern, print_and_return


class App:
    def open(self, query: str) -> str | bool:
        # TODO: Implement DRY

        # Checking for Opening Local Application
        result = check_pattern(query, "{} {}", [open_triggers.keys(), app_paths.keys()])
        if result != []:
            return self.__openApp(result[1], result[0], self.__getPath(result[1]))

        # Checking for Opening MS Application
        result = check_pattern(
            query, "{} {}{}", [open_triggers.keys(), ms_triggers, ms_app_paths.keys()]
        )
        if result != []:
            return self.__openApp(result[2], result[0], self.__getPath(result[2]))

        # Checking for Closing Local Application
        result = check_pattern(
            query, "{} {}", [close_triggers.keys(), app_paths.keys()]
        )
        if result != []:
            return self.__closeApp(result[1], result[0], self.__getPath(result[1]))

        # Checking for Closing MS Application
        result = check_pattern(
            query, "{} {}{}", [close_triggers.keys(), ms_triggers, app_paths.keys()]
        )
        if result != []:
            return self.__closeApp(result[2], result[0], self.__getPath(result[2]))

        # Checking for Opening Folders
        result = check_pattern(
            query,
            "{} {}{} {}",
            [open_triggers.keys(), folder_paths.keys(), suffix_triggers, dir_triggers],
        )
        if result != []:
            return self.__openApp(result[1], result[0], self.__getPath(result[1]))

        # Checking for Opening Windows Settings
        result = check_pattern(
            query,
            "{} {}",
            [
                open_triggers.keys(),
                ["settings|windows settings|local settings|device settings"],
            ],
        )
        if result != []:
            os.system("start ms-settings:")
            return f"{open_triggers[result[0]]} settings"

        # Checking for Opening Recycle Bin
        result = check_pattern(
            query,
            "{} {}",
            [
                open_triggers.keys(),
                [
                    "recycle bin|windows recycle bin|local recycle bin|device recycle bin"
                ],
            ],
        )
        if result != []:
            subprocess.Popen(["explorer", "shell:RecycleBinFolder"])
            return f"{open_triggers[result[0]]} recycle bin"

        return False

    def __openApp(self, app_name: str, trigger: str, paths: dict) -> str:
        os.startfile(paths[app_name][1])
        return f"{open_triggers[trigger]} {paths[app_name][0]}"

    def __closeApp(self, app_name: str, trigger: str, paths: dict) -> str:
        err_command = f"Can't {trigger} {paths[app_name][0]}!"
        if paths[app_name][0] in unclosable_triggers:
            return print_and_return(err_command)

        path = paths[app_name][1][paths[app_name][1].rfind("\\") + 1 :]
        try:
            subprocess.run(["taskkill", "/F", "/IM", path], check=True)
            return f"{close_triggers[trigger]} {paths[app_name][0]}"
        except subprocess.CalledProcessError as e:
            return err_command

    def __getPath(self, app_name: str):
        if app_name in app_paths:
            paths = app_paths
        elif app_name in ms_app_paths:
            paths = ms_app_paths
        elif app_name in folder_paths:
            paths = folder_paths
        return paths
