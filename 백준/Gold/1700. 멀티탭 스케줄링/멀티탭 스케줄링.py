from collections import deque
n,k=map(int,input().split())
seq=deque([*map(int,input().split())])
items_with_ord=[deque() for _ in range(k+1)]
inf=1000000
for idx,item in enumerate(seq):
    items_with_ord[item].append(idx)

sockets=set()
cnt=0
while len(sockets)!=n:
    if(seq):
        tmp=seq.popleft()
        sockets.add(tmp)
        items_with_ord[tmp].popleft()
    else:
        break

sockets=list(sockets)
while seq:
    p=seq.popleft()
    if p in sockets:
        items_with_ord[p].popleft()
        continue
    
    candidates=[]
    for i in range(n):
        if(items_with_ord[sockets[i]]):candidates.append((items_with_ord[sockets[i]][0],sockets[i]))
        else:candidates.append((inf,sockets[i]))#1000000 append
    candidates.sort()
    _,target=candidates[-1]
    target_idx=sockets.index(target)
    
    sockets[target_idx]=p
    items_with_ord[p].popleft()
    cnt+=1

print(cnt)