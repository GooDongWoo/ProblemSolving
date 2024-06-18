import sys
def cal2dot(dot1,dot2,dot3):
    x1,y1=dot1
    x2,y2=dot2
    x3,y3=dot3
    result=((x1*y2+x2*y3+x3*y1)-(x1*y3+x2*y1+x3*y2))/2
    return result
    
n=int(input())
dot_list=[]
for _ in range(n):
    dot_list.append(tuple(map(int,sys.stdin.readline().split())))

area=0
first_dot=dot_list[0]
for idx in range(1,len(dot_list)-1):
    area+=cal2dot(first_dot,dot_list[idx],dot_list[idx+1])

sys.stdout.write(f'{round(abs(area),1)}\n')