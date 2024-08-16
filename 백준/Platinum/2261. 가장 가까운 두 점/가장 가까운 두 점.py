import sys

def dist(p1, p2):
    return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2

def filter_pts(pts, m, d):
    return [p for p in pts if (pts[m][0] - p[0])**2 < d]

def sort_y(pts):
    return sorted(pts, key=lambda p: p[1])

def min_dist(pts):
    n = len(pts)
    if n <= 1:
        return float('inf')
    if n == 2:
        return dist(pts[0], pts[1])
    
    m = n // 2
    left = pts[:m]
    right = pts[m:]
    
    d_left = min_dist(left)
    d_right = min_dist(right)
    
    min_d = min(d_left, d_right)
    
    target = filter_pts(pts, m, min_d)
    target_sorted = sort_y(target)
    
    def compute_min_dist(ts):
        nonlocal min_d
        for i in range(len(ts) - 1):
            for j in range(i + 1, len(ts)):
                if (ts[i][1] - ts[j][1])**2 < min_d:
                    min_d = min(min_d, dist(ts[i], ts[j]))
                else:
                    break
        return min_d
    
    return min(min_d, compute_min_dist(target_sorted))

def sol():
    n = int(sys.stdin.readline())
    pts = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
    pts.sort(key=lambda p: p[0])
    print(min_dist(pts))

sol()
