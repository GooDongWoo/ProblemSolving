n=int(input())
l1=[*map(int,input().split())]
target=sum(l1)//n

cnter=0
for i in range(n-1):
    if(l1[i]==target):
        continue
    elif(l1[i]<target):
        cnter+=(target-l1[i])
        l1[i+1]=l1[i+1]-(target-l1[i])
        l1[i]=target
        
    elif(l1[i]>target):
        cnter+=(l1[i]-target)
        l1[i+1]-=(target-l1[i])
        l1[i]=target
        
print(cnter)