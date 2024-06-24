import sys
import heapq
n,k=map(int,sys.stdin.readline().split())
jewerly_list=[tuple(map(int,sys.stdin.readline().split())) for _ in range(n)]
bag_list=[int(sys.stdin.readline()) for _ in range(k)]
heapq.heapify(jewerly_list)
bag_list.sort()
ans=0
value_heap=[]
#않이!!!!!!!! 정렬된 2개 리스트로 힙으로 이리저리 하는거... 발상이 미친거 아닌가.. 머지소트랑 비슷하게 복잡도 줄이는데;; 하;; 각각의 정렬로 총 정렬을 이리저리 할 수 있다...
for bag_limit in bag_list:
    if(bag_limit>1000000):
        break
    while jewerly_list and jewerly_list[0][0]<=bag_limit:
        heapq.heappush(value_heap,-heapq.heappop(jewerly_list)[1])
    if(value_heap):
        ans-=heapq.heappop(value_heap)
sys.stdout.write(f'{ans}\n')

# 능지의 한계를 느꼈다...
'''
import sys
from bisect import bisect_left as bisec
n,k=map(int,sys.stdin.readline().split())
jewerly_list=[0]*n
bag_list=[0]*k
for i in range(n):
    jewerly_list[i]=tuple(map(int,sys.stdin.readline().split()))
for i in range(k):
    bag_list[i]=int(sys.stdin.readline())
jewerly_list.sort(key=lambda x:x[1],reverse=True)
bag_list.sort()
ans=jew_idx=0
while jew_idx<n and bag_list:
    bag_loc=bisec(bag_list,jewerly_list[jew_idx][0])
    if(bag_loc<k):
        ans+=jewerly_list[jew_idx][1]
        bag_list.remove(bag_list[bag_loc])
    jew_idx+=1
sys.stdout.write(f'{ans}\n')
'''