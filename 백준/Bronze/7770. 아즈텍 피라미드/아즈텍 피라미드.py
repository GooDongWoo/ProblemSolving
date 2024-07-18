n=int(input())
ans=1
while n>0:
    n-=(2*(ans**2)-2*ans+1)
    ans+=1
if(n<0):
    print(ans-2)
else:
    print(ans-1)