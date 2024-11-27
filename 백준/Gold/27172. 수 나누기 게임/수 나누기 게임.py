import sys
input=sys.stdin.readline

MAX = int(1e6)
n =  int(input())
l = [*map(int, input().split())]
h = [None] * (MAX + 1)
for i in range(n):
    h[l[i]] = 0

for i in range(1, MAX + 1):
    if not(h[i] is None):
        for j in range(2 * i, MAX + 1, i):
            if not(h[j] is None):
                h[i] += 1
                h[j] -= 1

for i in l:
    sys.stdout.write(f'{h[i]} ')