from requests import get
from datetime import datetime
import wikipedia

from src.triggers import show_triggers, using_triggers, person_triggers
from src.resources import week, search_clutter
from src.toolkit import check_pattern, print_and_return, replace_all

# TODO: Distribute Category-wise tasks to different functions/classes
class Custom:
    def __init__(self) -> None:
        pass

    def open(self, query: str) -> str | bool:
        # Checking for Showing IP Address
        if check_pattern(query, "{} ip address", [show_triggers]) != []:
            return print_and_return(
                f"Your IP Address is {get('https://api.ipify.org').text}."
            )

        # Checking for Information from Wikipedia
        result = check_pattern(query, "{} wikipedia", [using_triggers])
        if result != []:
            try:
                replace_all(query, {x: "" for x in [*search_clutter, result[0]]})
                wiki = wikipedia.summary(query, sentences=3)
                return print_and_return(f"According to wikipedia, {wiki}")
            except wikipedia.exceptions.PageError as e:
                return print_and_return("No Information Found!")

        trigger_format = [show_triggers, person_triggers]
        # Checking for today's date
        result = check_pattern(query, "{} {}today's date", trigger_format)
        if result != []:
            date = datetime.now()
            fdate = date.strftime("%d %B %Y")
            return print_and_return(f"Today's date is {week[date.weekday()]} {fdate}.")

        # Checking for current time
        result = check_pattern(query, "{} {}current time", trigger_format)
        if result != []:
            time = datetime.now().time()
            ctime = time.strftime("%I:%M:%S %p")
            return print_and_return(f"Current time is {ctime}")

        return False
