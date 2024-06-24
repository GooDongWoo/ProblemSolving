import sys
def multiply(m1,m2):
    res=[[0 for _ in range(8)] for _ in range(8)]
    for i in range(8):
        for j in range(8):
            tmp=0
            for k in range(8):
                tmp+=m1[i][k]*m2[k][j]%1000000007
            res[i][j]=tmp%1000000007
    return res
d=int(sys.stdin.readline())
adj_mat=[[0, 1, 1, 0, 0, 0, 0, 0],
        [1, 0, 1, 1, 0, 0, 0, 0],
        [1, 1, 0, 1, 1, 0, 0, 0],
        [0, 1, 1, 0, 1, 1, 0, 0],
        [0, 0, 1, 1, 0, 1, 0, 1],
        [0, 0, 0, 1, 1, 0, 1, 0],
        [0, 0, 0, 0, 0, 1, 0, 1],
        [0, 0, 0, 0, 1, 0, 1, 0]]
nTHmat=[[0]*i+[1]+[0]*(8-i) for i in range(8)]
while d:
    if(d&1):
        nTHmat=multiply(nTHmat,adj_mat)
        d-=1
    adj_mat=multiply(adj_mat,adj_mat)
    d//=2
print(nTHmat[0][0])