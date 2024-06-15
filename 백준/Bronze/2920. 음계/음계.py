a= list(map(int,input().split()))
a_sorted=sorted(a)
d_sorted=sorted(a,reverse=True)
asc_cnt=0
dsc_cnt=0

for i in range(len(a)):
    if(a[i]==a_sorted[i]):
        asc_cnt+=1
    if(a[i]==d_sorted[i]):
        dsc_cnt+=1

if(asc_cnt==len(a)):
    print('ascending')
elif(dsc_cnt==len(a)):
    print('descending')
else:
    print('mixed')