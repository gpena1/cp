# lower bound implementation
# for an array sorted by the
# comparator function `cmp`
def first_greq(arr,target,cmp):
    i,j = 0,len(arr)-1
    while i < j:
        m = i + (j-i) // 2
        if cmp(arr[m], target) >= 0:
            j = m
        else:
            i = m + 1
    if cmp(arr[i], target) < 0: return i + 1
    return i

# upper bound implementation
# for an array sorted by the
# comparator function `cmp`
def first_gr(arr,target,cmp):
    i,j = 0,len(arr)-1
    while i < j:
        m = i + (j-i) // 2
        if cmp(arr[m], target) > 0:
            j = m
        else:
            i = m + 1
    if cmp(arr[i], target) <= 0: return i + 1
    return i
