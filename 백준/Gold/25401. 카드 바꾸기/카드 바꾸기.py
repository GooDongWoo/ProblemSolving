import sys
input=sys.stdin.readline
from collections import defaultdict

n = int(input())
l = list(map(int, input().split()))
max_pair = (0, 0)
for i in range(n):
    d = defaultdict(int)
    for j in range(n):
        if i == j or ((l[j] - l[i]) % (j - i) != 0): continue
        if i > j:diff = (l[i] - l[j]) // (i - j)
        else:diff = (l[j] - l[i]) //(j - i)
        d[diff] += 1
    tmp = sorted(d.items(), key = lambda x: x[1])
    if tmp[-1][1] > max_pair[1]:
        max_pair = tmp[-1]

print(n - 1 - max_pair[1])