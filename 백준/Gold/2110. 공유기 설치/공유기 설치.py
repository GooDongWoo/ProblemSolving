import sys
from bisect import bisect_left

n,c=map(int,sys.stdin.readline().split())
h_list=[int(sys.stdin.readline()) for _ in range(n)]
h_list.sort()

#make parameter_search
def isPossible(mini_dist):
    global n,c,h_list   #n개가 있는데 cnter가 c가 될 수 있느냐? c가 되기도 전에 마지막에 도달하느냐
    cnter=1
    cur_idx=0
    cur_val=h_list[0]
    while cnter!=c:
        nxt_idx=bisect_left(h_list,cur_val+mini_dist)
        if(nxt_idx>=n):#계속 mini_dist만큼 가다보면
            return False
        cnter+=1
        cur_idx=nxt_idx
        cur_val=h_list[cur_idx]
    return True

#main flow
upper_bound=(h_list[-1]-h_list[0])//(c-1)
lower_bound=1
while lower_bound<=upper_bound:
    mid=(lower_bound+upper_bound)//2
    if(isPossible(mid)):
        lower_bound=mid+1
    else:
        upper_bound=mid-1
print(upper_bound)