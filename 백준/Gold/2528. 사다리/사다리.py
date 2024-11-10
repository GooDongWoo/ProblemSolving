import sys
input=sys.stdin.readline

n,l=map(int,input().split())
rods=[list(map(int,input().split())) for _ in range(n)]

def findDirectin(idx,ct):
    global l,rods
    cycle=2*(l-rods[idx][0])
    if cycle!=0:ct%=cycle
    if rods[idx][1]==0: # left->right
        if ct <= (l-rods[idx][0]):
            cur=(ct,rods[idx][0]+ct)
        else:
            left=ct-(l-rods[idx][0])
            cur=(l-rods[idx][0]-left,l-left)
    else:# right->left
        if ct <= (l-rods[idx][0]):
            cur=(l-rods[idx][0]-ct,l-ct)
        else:
            left=ct-(l-rods[idx][0])
            cur=(left,rods[idx][0]+left)
    return cur

def chck(fl,fr,sl,sr):
    global l
    if fl<=sl<=fr or fl<=sr<=fr or sl<=fl<=sr or sl<=fr<=sr:
        return True
    return False

time=0
for i in range(n-1):
    for tmid in range(l):
        fl,fr=findDirectin(i,time+tmid)
        sl,sr=findDirectin(i+1,time+tmid)
        if chck(fl,fr,sl,sr):
            time+=tmid
            break
print(time)