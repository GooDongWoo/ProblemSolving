import sys
input=sys.stdin.readline

n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
d1=dict()
for i in range(n):
    d1[a[i]]=i

d2=dict()
for i in range(n):
    if d1[b[i]]-i in d2:
        d2[d1[b[i]]-i].append(b[i])
    else:
        d2[d1[b[i]]-i]=[b[i]]
        
t=sorted(d2.keys())
print(*d2[t[-1]])