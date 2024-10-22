import sys
input = sys.stdin.readline
n,m=map(int,input().split())
ts=input()
if(ts[0]=='0'):ts=[]
else:ts=list(map(lambda x:int(x)-1,ts.split()))[1:]
true_knows=[0]*n
parties=[1]*m

memp=[[] for _ in range(n)]
pmem=[[] for _ in range(m)]
for i in range(m):
    pmem[i]=list(map(lambda x:int(x)-1,input().split()))[1:]
    for j in pmem[i]:
        memp[j].append(i)

target_party=set([])
for i in ts:
    true_knows[i]=1
    for j in memp[i]:
        parties[j]=0
        target_party.add(j)

target_party=list(target_party)

while target_party:
    p=target_party.pop()
    for i in pmem[p]:
        if(true_knows[i]==0):
            true_knows[i]=1
            for j in memp[i]:
                if(parties[j]==1):
                    target_party.append(j)
                    parties[j]=0
print(sum(parties))