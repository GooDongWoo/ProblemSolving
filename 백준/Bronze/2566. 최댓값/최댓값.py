mat=[list(map(int,input().split())) for _ in range(9)]
maxy=0
maxx=0
maxv=mat[0][0]
for i in range(9):
    for j in range(9):
        if(mat[i][j]>maxv):
            maxy=i
            maxx=j
            maxv=mat[i][j]
print(maxv)
print(maxy+1,maxx+1)
