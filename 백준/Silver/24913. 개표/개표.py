import sys
input = sys.stdin.readline

n, q = map(int, input().split())
psum = [0]*(n + 1)
max_idx = 0
tsum = 0
for _ in range(q):
    t, x, y = map(int, input().split())
    if (t == 1):
        y -= 1
        psum[y] += x
        tsum += x
        if y != n and psum[y] > psum[max_idx]:
            max_idx = y
    else:
        my = psum[n] + x
        if (my > psum[max_idx]) and ((my-1)*n >= (tsum - psum[n] + y)):
            print("YES")
        else:
            print("NO")