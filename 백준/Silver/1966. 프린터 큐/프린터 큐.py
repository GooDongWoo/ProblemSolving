from collections import deque
import heapq
n_test=int(input())
deq=deque()

for _ in range(n_test):
    num_paper, idx_target=map(int,input().split())
    priority_list=list(map(int,input().split()))
    #heap1=priority_list.copy() #최소힙이라 안됨 큰 순서대로 나가야하는데;;
    heap1=[0]*len(priority_list)
    for i in range(len(priority_list)):
        heap1[i]=-priority_list[i]
    heapq.heapify(heap1)
    deq=deque(priority_list)
    cnt=0
    #code
    while(deq):
        if(deq[0]==-heap1[0]):
            deq.popleft()
            heapq.heappop(heap1)
            cnt+=1
            if(idx_target==0):
                print(cnt)
                break
            idx_target-=1
        else:
            deq.append(deq.popleft())
            if(idx_target==0):
                idx_target=len(deq)-1
            else:
                idx_target-=1