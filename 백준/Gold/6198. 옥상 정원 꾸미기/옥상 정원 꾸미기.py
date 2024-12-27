import sys
input = sys.stdin.readline

n = int(input())
hs = [int(input()) for _ in range(n)]

stck = [hs[0]]
cnter = 0
for i in range(1, n):
    while stck and stck[-1] <= hs[i]:
        stck.pop()
    
    cnter += len(stck)
    
    stck.append(hs[i])

print(cnter)