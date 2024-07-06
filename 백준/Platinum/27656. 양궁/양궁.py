import sys
from collections import deque

def ccw(a, b, c):  # ab & ac -> outer product
    return (a[0]*b[1] + b[0]*c[1] + c[0]*a[1]) - (a[1]*b[0] + b[1]*c[0] + c[1]*a[0])

def convexHull(points):
    bottom = deque()
    for i in range(len(points)):
        while len(bottom) > 1 and ccw(points[bottom[-2]], points[bottom[-1]], points[i]) < 0:
            bottom.pop()
        bottom.append(i)
    bottom.pop()

    topside = deque()
    for i in range(len(points)-1, -1, -1):
        while len(topside) > 1 and ccw(points[topside[-2]], points[topside[-1]], points[i]) < 0:
            topside.pop()
        topside.append(i)
    topside.pop()

    bottom.extend(topside)
    return [points[i] for i in bottom]

def isInner(polygon, point):
    n = len(polygon)
    if n < 3:
        return False

    if ccw(polygon[0], polygon[1], point) < 0:
        return False
    if ccw(polygon[0], polygon[-1], point) > 0:
        return False

    left = 1
    right = n - 1
    while left + 1 < right:
        middle = (left + right) // 2
        if ccw(polygon[0], polygon[middle], point) >= 0:
            left = middle
        else:
            right = middle

    return ccw(polygon[left], point, polygon[right]) <= 0

def bisearch(polys, point):
    low = 0
    high = len(polys) - 1
    answer = 0
    while low <= high:
        mid = (low + high) // 2
        if isInner(polys[mid], point):
            answer = mid + 1
            low = mid + 1
        else:
            high = mid - 1
    return answer

n = int(sys.stdin.readline())
cols = sorted([tuple(map(int, sys.stdin.readline().split())) for _ in range(n)])  # just x and y sort not ccw sort
if len(cols) < 3:
    print(0)
    exit()

polygons = []
while len(cols) >= 3:
    hull = convexHull(cols)
    polygons.append(hull)
    cols = [p for p in cols if p not in hull]

q = int(sys.stdin.readline())
for _ in range(q):
    t_x, t_y = map(int, sys.stdin.readline().split())
    print(bisearch(polygons, (t_x, t_y)))