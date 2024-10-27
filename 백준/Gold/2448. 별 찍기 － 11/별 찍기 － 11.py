import sys
import math
input=sys.stdin.readline

def insert(y,x):
    global base,tmp
    by=len(base)
    bx=len(base[0])
    for i in range(by):
        for j in range(bx):
            tmp[i+y][j+x]=base[i][j]
    
    return

n=int(input())
k=int(math.log2(n//3))
base=[[" "," ","*"," "," "],
[" ","*"," ","*"," "],
["*","*","*","*","*"]]
y=3;x=5
for i in range(1,k+1):
    ny=y*2
    nx=x*2+1
    tmp=[[' ']*nx for _ in range(ny)]
    by=len(base)
    bx=len(base[0])
    insert(by,0)
    insert(by,bx+1)
    insert(0,((x-1)//2)+1)
    
    y,x=(ny,nx)
    base=tmp

for line in base:
    sys.stdout.write(f"{''.join(line)}\n")