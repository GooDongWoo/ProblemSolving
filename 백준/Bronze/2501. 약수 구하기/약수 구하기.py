import sys
input=sys.stdin.readline

n,k=map(int,input().split())

cands=[]
for i in range(1,n+1):
    if n%i==0:
        cands.append(i)
if len(cands)<k:
    print(0)
else:
    print(cands[k-1])