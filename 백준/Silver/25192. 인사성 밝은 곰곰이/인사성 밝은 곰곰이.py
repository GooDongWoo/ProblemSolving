import sys
input=sys.stdin.readline

n=int(input())
cnt=0

s1=set()
for _ in range(n):
    aa=input().strip()
    if aa=='ENTER':
        cnt+=len(s1)
        s1=set()
    else:
        s1.add(aa)
print(cnt+len(s1))