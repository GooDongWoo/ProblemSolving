import sys
input = sys.stdin.readline

def bsl(l1, target):
    start = 0
    end = len(l1) - 1
    while start <= end:
        mid = (start + end) // 2
        if l1[mid] < target:start = mid + 1
        else:end = mid - 1
    return start

MAX = int((2 ** 31) ** 0.5)
cache = [0] * (MAX + 2)
cache[1] = 1
for i in range(2, MAX + 2):
    cache[i] = ((i) * (i + 1) // 2) + ((i - 1) * (i) // 2)

t = int(input())
for _ in range(t):
    x, y = map(int, input().split())
    dist = y - x
    maximum_jump = bsl(cache, dist)
    diff = dist - cache[maximum_jump]
    plus_cnt = diff // maximum_jump if diff % maximum_jump == 0 else diff // maximum_jump + 1
    print(maximum_jump + maximum_jump - 1 + plus_cnt)