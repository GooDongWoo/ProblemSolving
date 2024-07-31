import sys
def binsearch():
    global items
    target=items[-1][1]
    start=0
    end=len(items)-1
    while start<=end:
        mid=(start+end)//2
        if items[mid][1]<target:
            start=mid+1
        else:
            end=mid-1
    return start

while 1:
    t=int(sys.stdin.readline())
    if(t==0):
        break
    items=[]
    for _ in range(t):
        name, l=sys.stdin.readline().split()
        l=float(l)
        items.append((name, l))
    items.sort(key=lambda x: x[1])
    for i in range(binsearch(),t):
        print(items[i][0], end=' ')
    print()