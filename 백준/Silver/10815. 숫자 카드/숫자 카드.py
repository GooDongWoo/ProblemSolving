import sys
from bisect import bisect_left
n=int(input())
n_list=list(map(int,sys.stdin.readline().split()))
n_list.sort()
m=int(input())
m_list=list(map(int,sys.stdin.readline().split()))
for item in m_list:
    t_idx=bisect_left(n_list,item)
    if(t_idx<n and n_list[t_idx]==item):
        sys.stdout.write('1 ')
    else:
        sys.stdout.write('0 ')