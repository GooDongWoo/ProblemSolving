import sys

m=int(sys.stdin.readline())
allsum=0
xor_sum=0
for _ in range(m):
    tmp=sys.stdin.readline().rstrip()
    a=int(tmp[0])
    b=int(tmp[2:]) if tmp[2:] else None
    if(a==1):
        allsum+=b
        xor_sum^=b
    elif(a==2):
        allsum-=b
        xor_sum^=b
    elif(a==3):
        sys.stdout.write(f'{allsum}\n')
    else:
        sys.stdout.write(f'{xor_sum}\n')