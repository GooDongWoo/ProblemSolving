import sys
input = sys.stdin.readline

l = []
for i in range(0, 24):
    for j in range(0, 60):
        for k in range(0, 60):
            tmp = int(f'{i:02}'+f'{j:02}'+f'{k:02}')
            l.append(tmp)

for _ in range(3):
    s, e = input().split()
    s = int(''.join(s.split(':')))
    e = int(''.join(e.split(':')))
    for i in range(len(l)):
        if (l[i] == s):
            sidx = i
        if (l[i] == e):
            eidx = i
    
    cnter = 0
    idx = sidx
    while idx != eidx:
        cnter += 1 if l[idx] %3==0 else 0
        idx = (idx+1)%len(l)
    cnter += 1 if l[idx] %3==0 else 0
    
    print(cnter)