import sys
item_num,bag_size = map(int,sys.stdin.readline().split())
dp = [[0] * 2020 for _ in range(10001)]
divided_item = [(0, 0)]

idx = 2
for _ in range(item_num):
    w,c,k = map(int,sys.stdin.readline().split())
    idx += 3

    i = k
    while i > 0:
        part = i - (i >> 1)
        divided_item.append((w * part, c * part))
        i >>= 1

for cap in range(1, bag_size + 1):
    for idx in range(1, len(divided_item)):
        dp[cap][idx] = dp[cap][idx - 1]

        if cap >= divided_item[idx][0]:
            dp[cap][idx] = max(dp[cap][idx], dp[cap - divided_item[idx][0]][idx - 1] + divided_item[idx][1])
sys.stdout.write(f'{dp[bag_size][len(divided_item) - 1]}')