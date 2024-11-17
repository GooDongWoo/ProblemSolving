import sys
from collections import deque
input=sys.stdin.readline

n,m=map(int,input().split())
mat1=[list(map(int,input().split())) for _ in range(n)]
m,k=map(int,input().split())
mat2=[list(map(int,input().split())) for _ in range(m)]

mat3=[[0]*k for _ in range(n)]
for i in range(n):
    for j in range(k):
        for a in range(m):
            mat3[i][j]+=mat1[i][a]*mat2[a][j]

for i in range(n):
    print(*mat3[i])