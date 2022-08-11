def bubble_sort(arr):
    for i in range(1,len(arr)):
        for j in range (0,len(arr)-i):
            if(arr[j] > arr[j+1]):
                arr[j],arr[j+1] = arr[j+1],arr[j]
    return arr

def bubble_sort_adv(arr):
    for i in range(1,len(arr)):
        changed = False
        for j in range (0,len(arr)-i):
            if(arr[j] > arr[j+1]):
                changed = True
                arr[j],arr[j+1] = arr[j+1],arr[j]
        if not changed:
            break
    return arr

def selection_sort(arr):
    for i in range(0,len(arr)):
        min = i
        for j in range(i+1,len(arr)):
            if arr[j] < arr[min]:
                min = j
        arr[i],arr[min] = arr[min],arr[i]
    return arr

def selection_sort_desc(arr):
    for i in reversed(range(0,len(arr))):
        min = i
        for j in range(0,i):
            if arr [j] < arr[min]:
                min = j
        arr[i],arr[min] = arr[min],arr[i]
    return arr

def insertion_sort(arr):
    for i in range(1,len(arr)):
        for j in reversed(range(1,i+1)):
            if arr[j] < arr[j-1]:
                arr[j],arr[j-1] = arr[j-1],arr[j]
            else:
                break
    return arr


if __name__ == '__main__': 
    example = [5,3,6,9,4]
    print("Example Array : "+str(example))
    rslt = bubble_sort(example)
    print("Using Bubble Sort: "+str(rslt))
    rslt = bubble_sort_adv(example)
    print("Using Advanced Bubble Sort: "+str(rslt))
    rslt = selection_sort(example)
    print("Using Selection Sort: "+str(rslt))
    rslt = selection_sort_desc(example)
    print("Using Selection Sort in Descending order: "+str(rslt))
    rslt = insertion_sort(example)
    print("Using Insertion Sort: "+str(rslt))