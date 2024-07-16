n=int(input())
if(n==1):
    print(1)
else:
    idx=1
    while (n-idx)>=0:
        n-=idx
        idx+=1
    print(idx-1)