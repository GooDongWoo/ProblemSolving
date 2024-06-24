import sys
from bisect import bisect_left
n=int(input())
item_list=list(map(int,sys.stdin.readline().split()))

dp_list=[int(1e9)+1 for _ in range(n)]
loc_list=[int(1e9)+1 for _ in range(n)]
for i in range(n):
    loc=bisect_left(dp_list,item_list[i])
    dp_list[loc]=item_list[i]
    loc_list[i]=loc

loc_max=max(loc_list)
sys.stdout.write(f'{loc_max+1}\n')
ans_list=[0]*(loc_max+1)
ans_list[loc_max]=item_list[loc_list.index(loc_max)]

target_loc=loc_max-1
idx=loc_list.index(loc_max)-1
while target_loc>-1:
    if(loc_list[idx]==target_loc):
        ans_list[target_loc]=item_list[idx]
        target_loc-=1
    idx-=1
sys.stdout.write(f"{' '.join(map(str,ans_list))}\n")