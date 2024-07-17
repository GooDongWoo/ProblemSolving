import sys
import heapq
n=int(sys.stdin.readline())
items=sorted([tuple(map(int,sys.stdin.readline().split())) for _ in range(n)])
room=[]
heapq.heappush(room,items[0][1])
itemidx=1
while itemidx<n:
    if(items[itemidx][0]<room[0]):
        heapq.heappush(room,items[itemidx][1])
    else:
        heapq.heappop(room)
        heapq.heappush(room,items[itemidx][1])
    itemidx+=1
print(len(room))