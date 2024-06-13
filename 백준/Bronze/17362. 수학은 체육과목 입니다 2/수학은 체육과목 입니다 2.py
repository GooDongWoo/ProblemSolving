n=int(input())
target=-1
if(n>5):
    k=(((n-6)//4)+1,((n-6)%4))# stair,finger
else:
    k=(0,n)
if(k[0]>0):
    if(k[0]%2!=0):#홀수 스텝일때
        target=4-k[1]
    else:
        target=2+k[1]
else:
    target=k[1]
print(target)