import sys
n=int(sys.stdin.readline())
d1=dict()
for _ in range(n):
    name,state=sys.stdin.readline().split()
    if state=='enter':
        d1[name]=1
    else:
        d1[name]=0
res=[]
for name,state in d1.items():
    if(state):
        res.append(name)
    
print('\n'.join(sorted(res,reverse=True)))