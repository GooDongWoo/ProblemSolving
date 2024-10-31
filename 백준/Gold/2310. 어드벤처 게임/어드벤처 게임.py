import sys
from collections import deque
input=sys.stdin.readline
class chamber:
    def __init__(self,args):
        self.type=args[0]
        self.cost=int(args[1])
        self.neighs=[*map(lambda x:int(x)-1,args[2:])]

while 1:
    n=int(input())
    if(n==0): break
    chambers=[chamber(list(input().split())[:-1]) for _ in range(n)]
    v=[-1]*n
    money=0
    if(chambers[0].type=='L'):money=max(chambers[0].cost,0)
    elif(chambers[0].type=='T'):money-=chambers[0].cost
    else:money=0
    if(money<0):
        print("No")
        continue
    q=deque([(0,money)])#index,left
    v[0]=money
    sFlag=False
    while q:
        cur,money=q.popleft()
        if cur==n-1:
            print("Yes")
            sFlag=True
            break
        for nxt in chambers[cur].neighs:
            if(chambers[nxt].type=='L'):newmoney=max(chambers[nxt].cost,money)
            elif(chambers[nxt].type=='T'):newmoney=money-chambers[nxt].cost
            else:newmoney=money
            if newmoney>=0 and newmoney>v[nxt]:
                v[nxt]=newmoney
                q.append((nxt,newmoney))
    if not sFlag:print("No")