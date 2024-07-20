import sys
n=int(sys.stdin.readline())
cannot=[1,3]
if(n in cannot):
    print(-1)
else:
    cnter,n=divmod(n,5)
    if(n in cannot):
        cnter-=1
        if(n==1):
            cnter+=3
        else:
            cnter+=4
    else:
        cnter+=n//2
    print(cnter)   