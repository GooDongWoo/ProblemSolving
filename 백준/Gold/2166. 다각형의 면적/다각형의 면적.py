import sys
def polygon_area(vertices):
    n = len(vertices)  # Number of vertices
    area = 0.0
    
    for i in range(n):
        x1, y1 = vertices[i]
        x2, y2 = vertices[(i + 1) % n]
        area += x1 * y2
        area -= y1 * x2
    
    area = abs(area) / 2.0
    return area
n=int(input())
dot_list=[]
for _ in range(n):
    dot_list.append(tuple(map(int,sys.stdin.readline().split())))
print(round(polygon_area(dot_list),1))

'''import sys
def cal2dot(dot1,dot2,dot3):
    x1,y1=dot1
    x2,y2=dot2
    x3,y3=dot3
    result=abs(((x1*y2+x2*y3+x3*y1)-(x1*y3+x2*y1+x3*y2))/2)
    return result
n=int(input())
dot_list=[]
for _ in range(n):
    dot_list.append(tuple(map(int,sys.stdin.readline().split())))
area=0
dot_list.append(dot_list[0])
for idx in range(0,len(dot_list),2):
    area+=cal2dot(dot_list[idx],dot_list[idx+1],dot_list[idx+2])
sys.stdout.write(f'{round(area,1)}\n')'''