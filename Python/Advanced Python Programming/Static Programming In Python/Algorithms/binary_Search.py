def binary_Search(_list, target):
    start = 0
    end = len(_list) - 1
    while start <= end:
        middle = (start + end) // 2

        if _list[middle] == target:
            return True
        else:
            if _list[middle] < target:
                start = middle + 1
            else:
                end = middle
    return False

