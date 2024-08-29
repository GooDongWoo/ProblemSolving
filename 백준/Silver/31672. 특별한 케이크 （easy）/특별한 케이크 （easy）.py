import sys
_ = sys.stdin.readline()
n = int(sys.stdin.readline())
d = [[list(map(int, sys.stdin.readline().split())) for _ in range(3)] for _ in range(n)]
answer = []
for i in range(n):
    cnds = {i + 1 for i in range(n)}
    for j in range(n):
        m = d[j][0][0]
        s = set(d[j][1])
        b = d[j][2][0]
        if i == j:b ^= 1
        if b:cnds &= s
        else:cnds -= s
    if i + 1 in cnds:
        answer.append(i + 1)
if answer:
    print(*answer)
else:
    print("swi")