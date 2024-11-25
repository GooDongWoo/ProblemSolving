import sys
from collections import defaultdict
input=sys.stdin.readline

def dist(x1, y1, x2, y2):
    global r
    if((x1 - x2)**2 + (y1 - y2)**2 <= r**2):return True
    else:return False

k, r = map(int, input().split())

m = int(input())
candidates = [tuple(map(int, input().split())) for _ in range(m)]

n = int(input())
sols = [list(map(int, input().split())) for _ in range(n)]

c_d = defaultdict(set)
for i in range(m):
    for j in range(n):
        if dist(*candidates[i], *sols[j][:-1]):
            c_d[candidates[i]].add(tuple(sols[j]))

res = []
tmp = [0]*k
def bt(idx,lidx):
    global k, m, tmp
    if idx == k:
        res.append(tmp[:])
    else:
        for i in range(lidx+1,m):
            tmp[idx] = i
            bt(idx + 1, i)

ans = 0
bt(0,-1)
for seq in res:
    tmp = set()
    for i in seq:
        tmp |= c_d[candidates[i]]
    can = 0 
    for _, _, i in tmp:
        can += i
    ans = max(ans, can)
print(ans)