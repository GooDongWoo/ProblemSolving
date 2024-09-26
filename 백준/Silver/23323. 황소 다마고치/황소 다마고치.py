import sys
input=sys.stdin.readline
t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    days=1
    while n!=1:
        n//=2
        days+=1
    days+=m
    print(days)