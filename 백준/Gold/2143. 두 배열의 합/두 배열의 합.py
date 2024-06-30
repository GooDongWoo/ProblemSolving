import sys
from bisect import bisect_left,bisect_right
#1번 풀이 not set 사용 
t=int(sys.stdin.readline())

n=int(sys.stdin.readline())
a=list(map(int,sys.stdin.readline().split()))
a_sum=[0]*(len(a)+1)
a_sum[1]=a[0]
for i in range(1,len(a)):
    a_sum[i+1]=a_sum[i]+a[i]
    
a_all_sum=[0]*((len(a))*(len(a)+1)//2)
k=0
for i in range(len(a)):
    for j in range(i+1,len(a)+1):
        a_all_sum[k]=a_sum[j]-a_sum[i]
        k+=1

m=int(sys.stdin.readline())
b=list(map(int,sys.stdin.readline().split()))
b_sum=[0]*(len(b)+1)
b_sum[1]=b[0]
for i in range(1,len(b)):
    b_sum[i+1]=b_sum[i]+b[i]
    
b_all_sum=[0]*((len(b))*(len(b)+1)//2)
k=0
for i in range(len(b)):
    for j in range(i+1,len(b)+1):
        b_all_sum[k]=b_sum[j]-b_sum[i]
        k+=1

a_all_sum.sort()
b_all_sum.sort()
a_start=0
b_end=len(b_all_sum)-1
cnter=0
while a_start<len(a_all_sum) and b_end>=0:
    if((a_all_sum[a_start]+b_all_sum[b_end])==t):#같으면 cnter+1, 그리고 각 리스트에서 같은 개수 세고 그만큼씩 a_s는 더하고, b_e는빼기
        a_cnt=bisect_right(a_all_sum,a_all_sum[a_start])-bisect_left(a_all_sum,a_all_sum[a_start])
        b_cnt=bisect_right(b_all_sum,b_all_sum[b_end])-bisect_left(b_all_sum,b_all_sum[b_end])
        cnter+=a_cnt*b_cnt
        a_start+=a_cnt
        b_end-=b_cnt
    elif((a_all_sum[a_start]+b_all_sum[b_end])<t):#총합이 작다 start+1
        a_cnt=bisect_right(a_all_sum,a_all_sum[a_start])-bisect_left(a_all_sum,a_all_sum[a_start])
        a_start+=a_cnt
        
    else:#총합이 크다 end-1
        b_cnt=bisect_right(b_all_sum,b_all_sum[b_end])-bisect_left(b_all_sum,b_all_sum[b_end])
        b_end-=b_cnt
print(cnter)
#2번 set 사용해서 풀어보기-> set사용하면 크기도 크고 시간도 잡아먹을 것 같은뎅