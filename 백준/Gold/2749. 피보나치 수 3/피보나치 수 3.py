import sys
input=sys.stdin.readline

MOD=1000000

n=int(input())

def matsq(mat1,mat2):
    length=len(mat1)
    tmp=[[0]*length for _ in range(length)]
    for i in range(length):
        for j in range(length):
            for k in range(length):
                tmp[i][j]+=mat1[i][k]*mat2[k][j]
            tmp[i][j]%=MOD
    return tmp

def matNsq(mat,N):
    if N==1:
        return mat
    elif N%2: #odd
        return matsq(matNsq(matsq(mat,mat),N//2),mat)
    else:   #even
        return matNsq(matsq(mat,mat),N//2)
        

mul=[[1,1],
 [1,0]]
res=matNsq(mul,n)
print(res[0][1])