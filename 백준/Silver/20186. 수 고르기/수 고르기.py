import heapq
n,k=map(int,input().split())
items=[*map(lambda x:-x,[*map(int,input().split())])]
heapq.heapify(items)
res=0
for i in range(k):
    res-=heapq.heappop(items)
res-=(k-1)*k//2
print(res)