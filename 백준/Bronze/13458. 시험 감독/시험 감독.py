import sys
import math
n=int(sys.stdin.readline())
items=[*map(int,sys.stdin.readline().split())]
a,b=map(int,sys.stdin.readline().split())
for i in range(n):
    items[i]=max(items[i]-a,0)
cnter=n
for i in range(n):
    cnter+=math.ceil(items[i]/b)
print(cnter)