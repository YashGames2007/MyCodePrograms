import re

def check_pattern(
    query: str,
    check_format: str,
    place_holdings: list[list[str]],
    depth: int = 0,
    current_pattern: list[str] = [],
) -> list[str]:
    # TODO: Make it Simple | Implement DRY
    depth += 1
    if depth == len(place_holdings):
        for key in place_holdings[-1]:
            if "|" in key:
                for match in key.split("|"):
                    if match in query:
                        current = [*current_pattern, key]
                        if re.search(f"{check_format.format(*current)}", query):
                            return current
            if key in query:
                current = [*current_pattern, key]
                if re.search(f"{check_format.format(*current)}", query):
                    return current
    else:
        for key in place_holdings[depth - 1]:
            if "|" in key:
                for match in key.split("|"):
                    if match in query:
                        current = [*current_pattern, key]
                        lst = check_pattern(query, check_format, place_holdings, depth, current)
                        if lst != []:
                            return lst
            if key in query:
                current = [*current_pattern, key]
                lst = check_pattern(query, check_format, place_holdings, depth, current)
                if lst != []:
                    return lst
    return []

def nth_substr(string: str, key: str, n: int) -> int:
    start = string.find(key)
    while start >= 0 and n > 1:
        start = string.find(key, start + 1)
        n -= 1
    return start

def replace_all(string: str, remap: dict) -> str:
    replaced_string = string
    for key, value in remap.keys():
        replaced_string.replace(key, value)
    return replaced_string

def print_and_return(string: str) -> str:
    print(string)
    return string
