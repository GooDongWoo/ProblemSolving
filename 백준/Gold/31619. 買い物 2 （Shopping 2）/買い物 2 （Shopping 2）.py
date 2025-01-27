import sys
from bisect import bisect_left, bisect_right
input = sys.stdin.readline

N, M, Q = map(int, input().split())

products = []
for i in range(N):
    price, type_ = map(int, input().split())
    products.append((price, type_))

prefix_sum = [0] * (N + 1)
for i in range(N):
    prefix_sum[i + 1] = prefix_sum[i] + products[i][0]

type_indices = [[] for _ in range(M+1)]
for i, (_, type_) in enumerate(products):
    type_indices[type_].append(i)

for _ in range(Q):
    day, L, R = map(int, input().split())
    L -= 1
    
    total = prefix_sum[R] - prefix_sum[L]
    
    discount = 0
    if type_indices[day]:
        start = bisect_left(type_indices[day], L)
        end = bisect_right(type_indices[day], R-1)
        
        for i in range(start, end):
            idx = type_indices[day][i]
            discount += products[idx][0] // 2
            
    print(total - discount)