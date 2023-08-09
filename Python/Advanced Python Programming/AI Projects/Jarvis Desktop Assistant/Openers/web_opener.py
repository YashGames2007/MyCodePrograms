import webbrowser

# import re

from src.triggers import web_triggers, ms_triggers, open_triggers
from src.paths import ms_webApp_paths, ms_website_paths, website_paths
from src.toolkit import check_pattern


class Web:
    browser_path = "C:/Program Files (x86)/Microsoft/Edge/Application/msedge.exe %s"

    def open(self, query: str) -> str | bool:
        # TODO: Implement DRY

        # Checking for Opening Websites
        result = check_pattern(
            query, "{} {}", [open_triggers.keys(), website_paths.keys()]
        )
        if result != []:
            return self.__openWeb(result[1], result[0], self.__getPath(result[1]))

        # Checking for Opening MS Websites
        result = check_pattern(
            query,
            "{} {}{}",
            [open_triggers.keys(), ms_triggers, ms_website_paths.keys()],
        )
        if result != []:
            return self.__openWeb(result[2], result[0], self.__getPath(result[2]))

        # Checking for Opening MS WebApps
        result = check_pattern(
            query,
            "{} {}{} {}",
            [open_triggers.keys(), ms_triggers, ms_webApp_paths.keys(), web_triggers],
        )
        if result != []:
            return self.__openWeb(result[2], result[0], self.__getPath(result[2]))

        return False

    def __openWeb(self, website: str, trigger: str, paths: dict) -> str:
        webbrowser.get(self.browser_path).open(paths[website][1])
        return f"{open_triggers[trigger]} {paths[website][0]}"

    def __getPath(self, website: str) -> dict:
        if website in website_paths:
            paths = website_paths
        elif website in ms_website_paths:
            paths = ms_website_paths
        elif website in ms_webApp_paths:
            paths = ms_webApp_paths
        return paths
