import sys
n,m=map(int,sys.stdin.readline().split())
list1=list(map(int,sys.stdin.readline().split()))
list1=[0]+list1
sum_list=list1.copy()
for i in range(1,len(list1)):
    sum_list[i]=sum_list[i-1]+sum_list[i]
for _ in range(m):
    start,end=map(int,sys.stdin.readline().split())
    sys.stdout.write(f'{sum_list[end]-sum_list[start-1]}\n')