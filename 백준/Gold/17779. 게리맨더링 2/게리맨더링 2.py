import sys
n=int(sys.stdin.readline())
mat=[list(map(int,sys.stdin.readline().split())) for _ in range(n)]
total_sum=sum([sum(i) for i in mat])
'''
(x, y), (x+1, y-1), ..., (x+d1, y-d1)
(x, y), (x+1, y+1), ..., (x+d2, y+d2)
(x+d1, y-d1), (x+d1+1, y-d1+1), ... (x+d1+d2, y-d1+d2)
(x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)
'''
def cal1(sr,sc,left,right):
    global mat
    res=0
    for i in range(0,sr):
        res+=sum(mat[i][:sc+1])
    for i in range(sr,sr+left):
        res+=sum(mat[i][:sc-(i-sr)])
    return res

def cal2(sr,sc,left,right):
    global mat
    res=0
    for i in range(0,sr):
        res+=sum(mat[i][sc+1:])
    for i in range(sr,sr+right+1):
        res+=sum(mat[i][sc+1+(i-sr):])
    return res

def cal3(sr,sc,left,right):
    global mat
    res=0
    for i in range(sr+left,sr+left+right+1):
        res+=sum(mat[i][:sc-left+(i-(sr+left))])
    for i in range(sr+left+right+1,n):
        res+=sum(mat[i][:sc+right-left])
    return res

def cal4(sr,sc,left,right):
    global mat
    res=0
    for i in range(sr+right+1,sr+left+right+1):
        res+=sum(mat[i][sc+right-(i-(sr+right+1)):])
    for i in range(sr+left+right+1,n):
        res+=sum(mat[i][sc+right-left:])
    return res
    
def F(sr,sc,left,right):
    global n,mat,total_sum,candidates
    tmp=[0]*5
    tmp[0]=cal1(sr,sc,left,right)
    tmp[1]=cal2(sr,sc,left,right)
    tmp[2]=cal3(sr,sc,left,right)
    tmp[3]=cal4(sr,sc,left,right)
    tmp[4]=total_sum-sum(tmp)
    candidates.append(max(tmp)-min(tmp))

candidates=[]
for i in range(n):
    for j in range(n):
        for d1 in range(1,n):
            for d2 in range(1,n):
                if(i+d1+d2<n and j+d2<n and j-d1>=0):
                    F(i,j,d1,d2)
print(min(candidates))