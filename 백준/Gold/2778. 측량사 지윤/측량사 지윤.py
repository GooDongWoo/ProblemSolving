import sys
input=sys.stdin.readline

def point_of_intersection(a1, b1, c1, a2, b2, c2):
    if b1 == 0:
        x = (b2 * c1 - b1 * c2) / (a2 * b1 - a1 * b2)
        y = -1 * (a2 / b2) * x - c2 / b2
    else:
        x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1)
        y = -1 * (a1 / b1) * x - c1 / b1

    return (x, y)

def is_parallel(a1, b1, a2, b2):
    return a1 * b2 - a2 * b1 == 0

def width_of_triangle(x1, x2, x3, y1, y2, y3):
    a = x1 * y2 + x2 * y3 + x3 * y1
    b = x2 * y1 + x3 * y2 + x1 * y3
    return 0.5 * abs(a - b)

def solve(t, equations):
    for i in range(t):
        a1, b1, c1 = equations[i][0]
        a2, b2, c2 = equations[i][1]
        a3, b3, c3 = equations[i][2]
        
        if is_parallel(a1, b1, a2, b2) or is_parallel(a1, b1, a3, b3) or is_parallel(a3, b3, a2, b2):
            print("0.0000")
            continue
        
        p1 = point_of_intersection(a1, b1, c1, a2, b2, c2)
        p2 = point_of_intersection(a1, b1, c1, a3, b3, c3)
        p3 = point_of_intersection(a3, b3, c3, a2, b2, c2)
        
        if p1 == p2 and p2 == p3:
            print("0.0000")
            continue
        
        print(f"{width_of_triangle(p1[0], p2[0], p3[0], p1[1], p2[1], p3[1]):.4f}")

t=int(input())
equations = [[list(map(int,input().split())) for _ in range(3)] for _ in range(t)]
solve(t, equations)