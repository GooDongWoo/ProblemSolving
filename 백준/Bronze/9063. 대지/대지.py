import sys
n=int(input())
max_x=-int(1e8)
max_y=-int(1e8)
min_x=int(1e8)
min_y=int(1e8)
for _ in range(n):
    list1=list(map(int,sys.stdin.readline().split()))
    max_x=max(max_x,list1[0])
    max_y=max(max_y,list1[1])
    min_x=min(min_x,list1[0])
    min_y=min(min_y,list1[1])
print((max_x-min_x)*(max_y-min_y))