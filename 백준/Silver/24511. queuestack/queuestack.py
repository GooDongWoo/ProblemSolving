import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
qORstack=[*map(int,input().split())]
contents=[*map(int,input().split())]
m=int(input())
ins=[*map(int,input().split())]
real=[contents[i] for i in range(n) if qORstack[i]==0]

ans=(real[::-1]+ins)[:len(ins)]
print(*ans)