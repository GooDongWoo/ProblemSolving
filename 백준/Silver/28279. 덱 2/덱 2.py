import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
deq=deque()
for _ in range(n):
    query=input().rstrip()
    if(query[0]=='1' or query[0]=='2'):
        query=query.split()
        if(query[0]=='1'):
            deq.append(int(query[1]))
        else:
            deq.appendleft(int(query[1]))
    elif(query[0]=='3'):
        if(deq):
            print(deq.pop())
        else:
            print(-1)
    elif(query[0]=='4'):
        if(deq):
            print(deq.popleft())
        else:
            print(-1)
    elif(query[0]=='5'):
        print(len(deq))
    elif (query[0] == '6'):
        if (deq):
            print(0)
        else:
            print(1)
    elif(query[0]=='7'):
        if(deq):
            print(deq[-1])
        else:
            print(-1)
    elif(query[0]=='8'):
        if(deq):
            print(deq[0])
        else:
            print(-1)
    