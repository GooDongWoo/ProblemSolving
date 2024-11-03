import sys
from collections import deque
input=sys.stdin.readline

n=int(input())
cmd_dict={'push':1,'pop':2,'size':3,'empty':4,'front':5,'back':6}
q=deque()
for _ in range(n):
    query=input().rstrip()
    cmd=0
    num=0
    if(len(query)>5):
        cmd,num=query.split()
        num=int(num)
    else:
        cmd=query
    if(cmd=='push'):
        q.append(num)
    elif(cmd=='pop'):
        if(q):
            print(q.popleft())
        else:
            print(-1)
    elif(cmd=='size'):
        print(len(q))
    elif(cmd=='empty'):
        if(q):
            print(0)
        else:
            print(1)
    elif(cmd=='front'):
        if(q):
            print(q[0])
        else:
            print(-1)
    elif(cmd=='back'):
        if(q):
            print(q[-1])
        else:
            print(-1)
            