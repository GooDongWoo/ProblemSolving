import heapq
from collections import deque

def solution(jobs):
    time=0
    j=deque(sorted(jobs))
    res=[]
    wait=[]
    while wait or j:
        while j and j[0][0]<=time:
            tmp=j.popleft()
            heapq.heappush(wait,(tmp[1],tmp[0]))
        #heapq.heapify(wait)
        if (wait):
            cost,start=heapq.heappop(wait)
            time+=cost
            res.append(time-start)
        else:
            time=j[0][0]
    answer = sum(res)//len(res)
    return answer