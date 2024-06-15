import sys
list_num,line_num=map(int,sys.stdin.readline().split())
list_=[0]*list_num
for i in range(line_num):
    num_from,num_to,ball_num=map(int,sys.stdin.readline().split())
    list_[num_from-1:num_to]=[ball_num]*(num_to-num_from+1)
for i in (list_):
    print(f'{i}',end=" " )
    