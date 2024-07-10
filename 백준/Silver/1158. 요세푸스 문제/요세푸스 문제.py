from collections import deque
n,k=map(int,input().split())
a=deque([i for i in range(1,n+1)])
res=[]
while a:
    a.rotate(-k)
    res.append(a.pop())
print(f'<{", ".join(map(str,res))}>')