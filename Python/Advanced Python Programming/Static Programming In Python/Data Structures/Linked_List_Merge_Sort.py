from linked_List import Linked_List as L

def mergeSort(linlist : object) -> object:
    print(1)
    if linlist.size() == 0 or linlist.size() == 1:
        return linlist
    left_Half, right_Half = split(l)
    left = mergeSort(left_Half)
    right = mergeSort(right_Half)

    return merge(left, right)


def split(linlist : object):
    print(2)
    if linlist is None or linlist.head is None:
        leftHalf = linlist
        rightHalf = None
        return leftHalf, rightHalf
    else:
        size = linlist.size()
        mid = size // 2
        midNode = linlist.get(mid - 1)
        leftHalf = linlist
        rightHalf = L()
        rightHalf.head = midNode.next_Node
        midNode.next_Node = None
    return leftHalf, rightHalf

def merge(left : object, right : object):
    print(3)
    merged = L()
    merged.prepend(0)

    current = merged.head

    left_Head = left.head
    right_Head = right.head

    while left_Head or right_Head:
        if left_Head is None:
            current.next_Node = right_Head
            right_Head = right_Head.next_Node
        elif right_Head is None:
            current.next_Node = left_Head
            left_Head = left_Head.next_Node
        else:
            leftData = left_Head.data
            rightData = right_Head.data

            if leftData < rightData:
                current.next_Node = left_Head
                left_Head = left_Head.next_Node
            else:
                current.next_Node = right_Head
                right_Head = right_Head.next_Node
        current = current.next_Node

    head = merged.head.next_Node
    merged.head = head

    print(merged)
    return merged
        

l = L()

for n in range(5):
    l.prepend(10 - n)
print("Unsorted: ", l)
a = mergeSort(l)
print("Sorted: ", a)