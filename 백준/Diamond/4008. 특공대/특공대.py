import sys
input = sys.stdin.readline

from collections import deque

def intersect_x(m1, k1, m2, k2):
    return (k2 - k1 + m1 - m2 - 1) // (m1 - m2)

def query(hull, x):
    while len(hull) >= 2:
        m1, k1 = hull[0]
        m2, k2 = hull[1]
        if m1 * x + k1 <= m2 * x + k2:
            hull.popleft()
        else:
            break
    return hull[0][0] * x + hull[0][1]

def add_line(hull, m, k):
    while len(hull) >= 2:
        m1, k1 = hull[-2]
        m2, k2 = hull[-1]
        if intersect_x(m1, k1, m2, k2) > intersect_x(m2, k2, m, k):
            hull.pop()
        else:
            break
    hull.append((m, k))

n = int(input())
a, b, c = map(int, input().split())
x = [0] + list(map(int, input().split())) 

psum = [0] * (n + 1)
for i in range(1, n + 1):
    psum[i] = psum[i-1] + x[i]

dp = [0] * (n + 1)
hull = deque([(0, 0)])  

for i in range(1, n + 1):
    X = psum[i]
    
    curr = query(hull, X)
    
    dp[i] = curr + a * X * X + b * X + c
    
    m = -2 * a * X  
    k = a * X * X - b * X + dp[i]  
    add_line(hull, m, k)

print(dp[n])