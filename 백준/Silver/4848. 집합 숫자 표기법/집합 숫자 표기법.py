import sys
sets=[0]*16
sets[0]='{}'
sets[1]='{'+sets[0]+'}'
for i in range(2,16):
    tmp=[]
    for j in range(i):
        tmp.append(sets[j])
    
    sets[i]='{' + (','.join(tmp)) + '}'

dict1=dict()
dict2=dict()
for i in range(16):
    dict1[sets[i]]=i
    dict2[i]=sets[i]

t=int(sys.stdin.readline())
for _ in range(t):
    a=sys.stdin.readline().rstrip()
    b=sys.stdin.readline().rstrip()
    sys.stdout.write(f'{dict2[dict1[a]+dict1[b]]}\n')