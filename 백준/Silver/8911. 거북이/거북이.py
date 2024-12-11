import sys
input = sys.stdin.readline

dy_dx = [(1, 0),(0, 1),(-1, 0),(0, -1)] #하, 오, 위, 왼

t = int(input())
for _ in range(t):
    drt = 2
    sy = sx = 0
    l1 = [(sy, sx)]
    opers = input().rstrip()
    for i in range(len(opers)):
        oper = opers[i]
        if oper == 'F':
            sy += dy_dx[drt][0]
            sx += dy_dx[drt][1]
            l1.append((sy,sx))
        elif oper == 'B':
            sy += dy_dx[(drt + 2) % 4][0]
            sx += dy_dx[(drt + 2) % 4][1]
            l1.append((sy,sx))
        elif oper == 'L':
            drt = (drt + 1) % 4
        elif oper == 'R':
            drt = (drt - 1) % 4
    
    miny = minx = maxy = maxx = 0
    for i in range(len(l1)):
        miny = min(miny, l1[i][0])
        maxy = max(maxy, l1[i][0])
        
        minx = min(minx, l1[i][1])
        maxx = max(maxx, l1[i][1])
    
    sys.stdout.write(f'{(maxx - minx) * (maxy - miny)}\n')