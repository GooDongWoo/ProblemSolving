import sys

n,q=map(int,sys.stdin.readline().split())
slots=[0]*n
for _ in range(q): 
    l,i=map(int,sys.stdin.readline().split())
    for j in range(l-1,n,i):
        slots[j]=1
print(n-sum(slots))