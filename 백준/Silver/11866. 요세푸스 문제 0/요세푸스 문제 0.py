import sys
input=sys.stdin.readline
print=sys.stdout.write
from collections import deque

n,k = map(int, input().split())
deq=deque([i for i in range(1,n+1)])
cnt=1
ans_list=[]
while(deq):
    if(cnt!=k):
        deq.append(deq.popleft())
        cnt+=1
    else:
        ans_list.append(deq.popleft())
        cnt=1

print(f'<')
for i in ans_list[:-1]:
    print(f'{i}, ')
print(f'{ans_list[-1]}')
print(f'>\n')