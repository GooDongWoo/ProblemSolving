import sys

input = sys.stdin.readline

a, b = map(int, input().split())
na, nb = max((a + b)//2, (a - b)//2),  min((a + b)//2, (a - b)//2)
if (a + b) % 2 != 0 or (a - b) % 2 != 0 or na <0 or nb <0:
    print(-1)
else:
    print(na, nb)