import sys
input=sys.stdin.readline

n=int(input())
stack=[]
for _ in range(n):
    query=input().rstrip()
    qtype=query[0]
    if(qtype=='1'):
        _,x=map(int,query.split())
        stack.append(x)
    elif(qtype=='2'):
        if(stack):
            print(stack.pop())
        else:
            print(-1)
    elif(qtype=='3'):
        print(len(stack))
    elif(qtype=='4'):
        if(stack):
            print(0)
        else:
            print(1)
    elif(qtype=='5'):
        if(stack):
            print(stack[-1])
        else:
            print(-1)