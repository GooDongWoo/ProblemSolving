n_test=int(input())
weight=[0]*50
height=[0]*50
rank=[0]*50

for i in range(n_test):
    weight[i],height[i]=map(int,input().split())

for i in range(n_test):
    for j in range(n_test):
        if((weight[i] < weight[j]) and (height[i] < height[j])):
            rank[i]+=1

for i in range(n_test):
    print(rank[i]+1,end=' ')