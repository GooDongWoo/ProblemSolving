n=int(input())
if(n!=0):
    tmp=1
    result=1
    while tmp!=n+1:
        result*=tmp
        tmp+=1
    print(result)
else:
    print(1)
    