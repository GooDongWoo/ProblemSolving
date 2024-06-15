import heapq
import sys
test_case=int(input())
list1=[]
for _ in range(test_case):
    tmp=int(sys.stdin.readline())
    if(tmp==0):
        if (list1):
            sys.stdout.write(f'{heapq.heappop(list1)}\n')
        else:
            sys.stdout.write(f'0\n')
    else:
        heapq.heappush(list1,tmp)