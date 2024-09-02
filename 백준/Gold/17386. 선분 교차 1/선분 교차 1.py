def ccw(x1, y1, x2, y2, x3, y3):
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)

def is_intersect(x1, y1, x2, y2, x3, y3, x4, y4):
    # ccw 계산
    ccw1 = ccw(x1, y1, x2, y2, x3, y3)
    ccw2 = ccw(x1, y1, x2, y2, x4, y4)
    ccw3 = ccw(x3, y3, x4, y4, x1, y1)
    ccw4 = ccw(x3, y3, x4, y4, x2, y2)

    if ccw1 * ccw2 < 0 and ccw3 * ccw4 < 0:
        return True
    if ccw1 == 0 and on_segment(x1, y1, x2, y2, x3, y3):
        return True
    if ccw2 == 0 and on_segment(x1, y1, x2, y2, x4, y4):
        return True
    if ccw3 == 0 and on_segment(x3, y3, x4, y4, x1, y1):
        return True
    if ccw4 == 0 and on_segment(x3, y3, x4, y4, x2, y2):
        return True
    return False

def on_segment(x1, y1, x2, y2, x, y):
    return min(x1, x2) <= x <= max(x1, x2) and min(y1, y2) <= y <= max(y1, y2)

# 입력받기
x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())

# 교차 여부 확인
if is_intersect(x1, y1, x2, y2, x3, y3, x4, y4):
    print(1)
else:
    print(0)
