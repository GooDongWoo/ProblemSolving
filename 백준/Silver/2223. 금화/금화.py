t,x,m=map(int,input().split())
minimum_m=int(1e9)
for _ in range(m):
    d,s=map(int,input().split())
    tmp= d//s if(d/s==d//s) else d//s +1
    if(tmp<minimum_m):
        minimum_m=tmp
        m_pair=[d,s]
if(m==0):
    print(x*t)
    exit()
origin=m_pair[0]
time=0
golds=0
while time<t:
    if(m_pair[0]-m_pair[1]<=0):
        time+=1
        if(m_pair[0]<origin):
            m_pair[0]+=m_pair[1]
    else:
        time+=1
        golds+=x
        m_pair[0]-=m_pair[1]
print(golds)