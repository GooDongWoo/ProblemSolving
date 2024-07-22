import sys
k=int(sys.stdin.readline())
iolist=[*map(int,sys.stdin.readline().split())]
node=[0]*(2**k)
chckcnter=0
def ioalloc(idx=1):
    global k,iolist,node,chckcnter
    if(2*idx<2**k):
        ioalloc(2*idx)
    node[idx]=iolist[chckcnter]
    chckcnter+=1
    if((2*idx+1)<2**k):
        ioalloc(2*idx+1)

ioalloc()
idx=1
cnter=1
while idx<(2**k):
    print(*node[idx:idx+cnter])
    idx+=cnter
    cnter*=2