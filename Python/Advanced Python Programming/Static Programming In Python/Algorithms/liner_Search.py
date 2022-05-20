def linear_Search(_list, target):
    for index in range(len(_list)):
        if _list[index] == target:
            return index
    return None

