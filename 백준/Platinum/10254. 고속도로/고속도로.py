import sys

def ccw(p, o, q):
    return (o[0] - p[0]) * (q[1] - o[1]) - (o[1] - p[1]) * (q[0] - o[0])

def dist(p, q):
    return (q[0] - p[0]) ** 2 + (q[1] - p[1]) ** 2

def convex_hull(points):
    points.sort(key=lambda p: p[1])
    points.sort()
    
    upper, lower = [], []
    for point in points:
        while len(upper) > 1 and ccw(upper[-2], upper[-1], point) >= 0:
            upper.pop()
        while len(lower) > 1 and ccw(lower[-2], lower[-1], point) <= 0:
            lower.pop()
        upper.append(point)
        lower.append(point)
    
    return upper + lower[-2:0:-1]

def get_polygons(hull):
    i, j = 0, 0
    max_pair = []

    while abs(ccw(hull[-1], hull[0], hull[j + 1])) > abs(ccw(hull[-1], hull[0], hull[j])):
        j += 1
    
    while True:
        max_pair.append((i, j))
        while abs(ccw(hull[i], hull[i + 1], hull[(j + 1) % len(hull)])) > abs(ccw(hull[i], hull[i + 1], hull[j])):
            j += 1
            if j == len(hull):
                return max_pair
            max_pair.append((i, j))
        
        if j < len(hull) - 1 and abs(ccw(hull[i], hull[i + 1], hull[j + 1])) == abs(ccw(hull[i], hull[i + 1], hull[j])):
            max_pair.append((i, j + 1))
        
        i += 1
        if i == len(hull) - 1:
            break

    return max_pair

def solve():
    for _ in range(int(sys.stdin.readline())):
        n = int(sys.stdin.readline())
        points = [tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]
        hull = convex_hull(points)
        max_dist = 0
        lp, rp = 0, 0
        max_pair = get_polygons(hull)
        for i, j in max_pair:
            d = dist(hull[i], hull[j])
            if max_dist < d:
                max_dist = d
                lp, rp = i, j
        
        print(*hull[lp], *hull[rp])

solve()
