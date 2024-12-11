import sys
from bisect import bisect_left as bs
input = sys.stdin.readline

n = int(input())
l = [int(input()) for _ in range(n)]
width = int(input())
q = int(input())
qs = [int(input()) for _ in range(q)]

prefix_sum = l.copy()
mid_list = [0] * n
mid_list[0] = prefix_sum[0] / 2
for i in range(1, n):
    prefix_sum[i] += prefix_sum[i - 1]
    mid_list[i] = prefix_sum[i - 1] + (l[i] / 2)

target = width / 2
s_idx = bs(mid_list, target)
e_idx = bs(mid_list, prefix_sum[-1] - target)

for i in range(q):
    query = qs[i] - 1
    if s_idx > query:
        sys.stdout.write(f'0.00\n')
    elif query >= e_idx:
        sys.stdout.write(f'{max(prefix_sum[-1] - target * 2, 0):.2f}\n')
    else:
        sys.stdout.write(f'{(mid_list[query] - target):.2f}\n')