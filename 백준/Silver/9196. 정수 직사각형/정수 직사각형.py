import sys
input=sys.stdin.readline

daps = []
MAX = 150
for i in range(1, MAX):
    for j in range(i+1, MAX + 1):
        daps.append((i**2 + j**2, i, j))
daps.sort()

while 1:
    h, w =map(int, input().split())
    if h == 0 and w == 0: break
    target = h**2 + w**2
    idx = 0
    while idx < len(daps):
        if daps[idx][0] > target or (daps[idx][0] == target and daps[idx][1] > h):
            print(daps[idx][1], daps[idx][2])
            break
        idx += 1