a=list(map(int,input().split()))
tmp=0
for i in a:
    tmp+=pow(i,2)
tmp%=10
print(tmp)