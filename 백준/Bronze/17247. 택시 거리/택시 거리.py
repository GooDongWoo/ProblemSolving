n,m=map(int,input().split())
mat=[list(map(int,input().split())) for _ in range(n)]
l=[]
for i in range(n):
    for j in range(m):
        if(mat[i][j]):
            l.append((i,j))

sy,sx=l[0]
ey,ex=l[1]
print(abs(sy-ey)+abs(sx-ex))