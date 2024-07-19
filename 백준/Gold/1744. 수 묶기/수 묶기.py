import sys
n=int(sys.stdin.readline())
mlist=[]
zlist=[]
plist=[]
olist=[]
for _ in range(n):
    tmp=int(sys.stdin.readline())
    if(tmp>1):
        plist.append(tmp)
    elif(tmp==0):
        zlist.append(tmp)
    elif(tmp==1):
        olist.append(tmp)
    else:
        mlist.append(tmp)
res=0
mlist.sort()
plist.sort()
if(len(plist)&1):
    for i in range(len(plist)-1,0,-2):#홀수면 잘되고
        res+=plist[i]*plist[i-1]
    res+=plist[0]
else:
    for i in range(len(plist)-1,0,-2):#짝수면 잘된다.
        res+=plist[i]*plist[i-1]
    
if(len(mlist)&1):
    for i in range(0,len(mlist)-1,2):
        res+=mlist[i]*mlist[i+1]
    if not (zlist):
        res+=mlist[-1]
else:
    for i in range(0,len(mlist),2):
        res+=mlist[i]*mlist[i+1]

print(res+len(olist))