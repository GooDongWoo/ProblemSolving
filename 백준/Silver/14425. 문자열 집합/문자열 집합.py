import sys
n,m=map(int,sys.stdin.readline().split())
d1=set()
for _ in range(n):
    d1.add(sys.stdin.readline().rstrip())

cnter=0
for _ in range(m):
    if(sys.stdin.readline().rstrip() in d1):
        cnter+=1

print(cnter)