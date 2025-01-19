import sys
input = sys.stdin.readline

N = 100
psum = [0] * N
psum[0] = 1
for i in range(1, N):
    psum[i] = (2 ** i) + (2 * psum[i-1])

begin, end = map(int, input().split())

def F(num):
    global psum
    if num == 0: return 0
    t = []
    while num != 0:
        t.append(num % 2)
        num //= 2
    
    res = sum(t)
    for i in range(len(t) - 1, 0, -1):
        if (t[i] == 1):
            res += psum[i-1] + ((2 ** (i)) * sum(t[i+1:]))
    if t[0] == 1: res += sum(t[1:])
    return res

print(F(end) - F(begin - 1))