_=input()
tmp=sum(list(map(int,input().split())))
if(tmp>0):
    print('Right')
elif(tmp<0):
    print('Left')
else:
    print('Stay')