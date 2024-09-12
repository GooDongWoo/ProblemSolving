def find2(ants,bar_length):
    max1=0
    min1=int(1e9)
    for i in ants:
        min1=min(abs(bar_length/2 - i),min1)
        max1=max(max(bar_length-i,i),max1)
    return min1,max1

import sys
t=int(sys.stdin.readline())
for _ in range(t):
    l,n=map(int,sys.stdin.readline().split())
    ants=[int(sys.stdin.readline()) for _ in range(n)]
    min1,max1=find2(ants,l)
    min1=int(l-(min1+(l/2)))
    print(min1,max1)