import sys
from collections import deque
# 점 클래스 정의
class Point():
    def __init__(self, x=0, y=0, vx=0, vy=0):
        self.x = x
        self.y = y
        self.vx = vx
        self.vy = vy
    def __lt__(self, other):
        if self.vy * other.vx != self.vx * other.vy:
            return self.vy * other.vx < self.vx * other.vy  # 각도 비교
        if self.y != other.y:
            return self.y < other.y  # y 좌표 비교
        return self.x < other.x  # x 좌표 비교
    def __sub__(self,other):
        return Point(int(self.x-other.x),int(self.y-other.y))
    def length(self):
        return ((((self.x)**2) + ((self.y)**2))**(1/2))
    def __mul__(self,other):
        return self.x*other.x + self.y*other.y
    
# 벡터 AB와 벡터 AC의 CW/CCW 판별 함수
def ccw(A, B, C):
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x)
def findMinNSwap():
    global points
    idx=0
    min_y,min_x=int(1e5),int(1e5)
    for i in range(len(points)):
        if(points[i].y<min_y):
            min_y,min_x=points[i].y,points[i].x
            idx=i
        elif(points[i].y==min_y and points[i].x<min_x):
            min_y,min_x=points[i].y,points[i].x
            idx=i
    points[0],points[idx]=points[idx],points[0]
N= int(sys.stdin.readline())
points = [Point(*tuple(map(float,sys.stdin.readline().split()))) for _ in range(N)]
points_set=set(points)
# 점들을 y좌표 -> x좌표 0번 점이 제일 아래 제일 왼쪽
findMinNSwap()#points.sort()
for i in range(1, N):
    points[i].vx = points[i].x - points[0].x  # 기준점으로부터의 상대 x 좌표
    points[i].vy = points[i].y - points[0].y  # 기준점으로부터의 상대 y 좌표
# 0번을 제외한 점들을 반시계 방향으로 정렬
points[1:] = sorted(points[1:])
stck = deque()  # 스택 선언
# 스택에 처음 2개의 점을 넣음
stck.append(points[0])
stck.append(points[1])
next_point = 2  # 다음 점 인덱스 초기화
# 모든 점을 훑음
while next_point < N:
    # 스택에 2개 이상의 점이 남아있는 한...
    while len(stck) >= 2:
        first = stck.pop()  # 최상단 점 제거
        second = stck[-1]  # 그 다음 점 인덱스
        # 스택 최상단 점 2개와 다음 점의 관계가 CCW일 때까지 스택 pop
        if ccw(second, first, points[next_point]) > 0:
            stck.append(first)  # CCW면 다시 스택에 넣음
            break
    # 다음 점을 스택에 넣음
    stck.append(points[next_point])
    next_point += 1
# 이제 스택에 컨벡스 헐 정점들이 순서대로 쌓여 있음
polygon=list(stck)
nd=len(polygon)
lengths=[0]*nd
for i in range(1,nd):
    lengths[i-1]=(polygon[i]-polygon[i-1]).length()
lengths[-1]=(polygon[0]-polygon[-1]).length()
print(f'{sum(lengths):.2f}')