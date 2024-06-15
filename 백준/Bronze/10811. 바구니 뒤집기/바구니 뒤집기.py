import sys
list_num,line_num=map(int,sys.stdin.readline().split())
list_1=list(range(1,list_num+1))
for i in range(line_num):
    num_from,num_to=map(int,sys.stdin.readline().split())
    tmp=list_1[num_from-1:num_to]
    list_1[num_from-1:num_to]=tmp[::-1]

for i in list_1:
    print(f'{i}',end=" ")