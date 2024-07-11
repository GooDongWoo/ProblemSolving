import sys
mat=[[0]*100 for _ in range(100)]
n=int(input())
for _ in range(n):
    left,bottom=map(int,input().split())
    for i in range(10):
        for j in range(10):
            mat[bottom+i][left+j]=1
res=0
for i in range(100):
    res+=(sum(mat[i]))
print(res)