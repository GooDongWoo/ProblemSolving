import sys
input=sys.stdin.readline

a,b=input().split()

na,nb=int(a[::-1]),int(b[::-1])
print(max(na,nb))

