import sys
from collections import deque
n=int(sys.stdin.readline())
d=deque([i for i in range(1,n+1)])
if((n//2)%2==0):print(n)
else:print(n-1)

d.pop()# n을 팝
while len(d)!=1:
    first=d.pop()
    second=d.pop()
    sys.stdout.write(f'{first} {second}\n')
    d.appendleft(abs(first-second))

d.appendleft(n)
first=d.pop()
second=d.pop()
sys.stdout.write(f'{first} {second}\n')