import sys
from bisect import bisect_left
n=int(input())

array = list(map(int,sys.stdin.readline().split()))
dp = [1]
x = [array[0]]

for i in range(1, len(array)):
    if array[i] > x[-1]: 
        x.append(array[i])
        dp.append(dp[-1] + 1) 
    else: 
        idx = bisect_left(x, array[i])
        x[idx] = array[i]

sys.stdout.write(f'{dp[-1]}')