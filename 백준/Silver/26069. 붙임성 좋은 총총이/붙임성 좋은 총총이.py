import sys
input=sys.stdin.readline
n=int(input())
cnt=0
s1=set()
s1.add('ChongChong')
for _ in range(n):
    a,b=input().split()
    if(a in s1 or b in s1):
        s1.add(a)
        s1.add(b)
print(len(s1))