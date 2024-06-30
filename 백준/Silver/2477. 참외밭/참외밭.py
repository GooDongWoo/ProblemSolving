import sys
k=int(input())

dy_dx=[(0,1),(0,-1),(1,0),(-1,0)]
start=(0,0)
dir_list=[]
for _ in range(6):
    dir_list.append(start)
    tmp=list(map(int,sys.stdin.readline().split()))
    start=(start[0]+(dy_dx[tmp[0]-1][0]*tmp[1]),start[1]+(dy_dx[tmp[0]-1][1]*tmp[1]))

dir_list.append((0,0))
left=0
right = 0
for i in range(6):
    left += dir_list[i][0]*dir_list[i+1][1]
    right += dir_list[i+1][0]*dir_list[i][1]
answer = abs(left-right)/2
print(int(answer*k))