def split(l):
    return (l[ : len(l) // 2], l[len(l) // 2 : ])

def merge(left, right):
    l = []
    i, j = 0, 0

    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            l.append(left[i])
            i += 1
        else:
            l.append(right[j])
            j += 1

    while i < len(left):
        l.append(left[i])
        i += 1

    while j < len(right):
        l.append(right[j])
        j += 1

    return l

def mergeSort(l : list) -> list:
    if len(l) <= 1:
        return l

    left_Half, right_Half = split(l)
    left = mergeSort(left_Half)
    right = mergeSort(right_Half)

    return merge(left, right)
    
import random
randList = [random.randint(1, 100) for i in range(1000)]
# print(randList)
print("Processing...")
s = mergeSort(randList)
if s == sorted(randList):
    print("List is Sorted!")
    print(randList, s)
else:
    print("List Dosen't get Fully Sorted.")
