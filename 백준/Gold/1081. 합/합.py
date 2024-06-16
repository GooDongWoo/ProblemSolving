import sys
n, m = map(int, sys.stdin.readline().split())
tmp=[0]*1000
n_arr = [0 for _ in range(10)]
m_arr = [0 for _ in range(10)]
n -= 1
score = 1
while n != 0:
    while n % 10 != 9:
        for i in str(n):
            n_arr[int(i)] += score
        n -= 1
    if n < 10:
        for i in range(n + 1):
            n_arr[i] += score
        n_arr[0] -= score
        break
    else:
        for i in range(10):
            n_arr[i] += (n // 10 + 1) * score
    n_arr[0] -= score
    score *= 10
    n //= 10
score = 1
while m != 0:
    while m % 10 != 9:
        for i in str(m):
            m_arr[int(i)] += score
        m -= 1
    if m < 10:
        for i in range(m + 1):
            m_arr[i] += score
        m_arr[0] -= score
        break
    else:
        for i in range(10):
            m_arr[i] += (m // 10 + 1) * score
    m_arr[0] -= score
    score *= 10
    m //= 10
ans = 0
for i in range(10):
    ans += (m_arr[i] - n_arr[i]) * i
sys.stdout.write(f'{ans}')