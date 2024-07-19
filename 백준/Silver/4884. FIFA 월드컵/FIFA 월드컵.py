import sys
while 1:
    g,t,a,d=map(int,sys.stdin.readline().split())
    if(g==-1 and t==-1 and a==-1 and d==-1):
        break
    games=(((t*(t-1))//2)*g)
    c=g*a+d
    bitcnter=0
    lstbit=0
    while (c):
        if(c&1):bitcnter+=1
        c>>=1
        lstbit+=1
    
    if(c%2==0 and bitcnter==1):
        rem=0
        team=(2**(lstbit-1))
    else:
        rem=(2**(lstbit))-(g*a+d)
        team=(2**(lstbit))
    
    while team:
        team//=2
        games+=team
    sys.stdout.write(f'{g}*{a}/{t}+{d}={games}+{rem}\n')