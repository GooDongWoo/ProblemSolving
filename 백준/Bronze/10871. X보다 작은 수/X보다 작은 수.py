import sys
num,val=map(int,sys.stdin.readline().split())

tmp_list=[]
tmp_list.extend(map(int,sys.stdin.readline().split()))

for i in tmp_list:
    if i<val:
        print(i,end=" ")
