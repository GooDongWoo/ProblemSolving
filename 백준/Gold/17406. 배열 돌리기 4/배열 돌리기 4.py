def makeorder(k):
    cases=[]
    chck=[0]*k
    res=[0]*k
    def bt(idx):
        nonlocal cases,chck,res
        if(idx==k):
            cases.append(res.copy())
        else:
            for i in range(k):
                if(chck[i]==1):continue
                chck[i]=1
                res[idx]=i
                bt(idx+1)
                chck[i]=0
    bt(0)
    return cases

n,m,k=map(int,input().split())
origin_mat=[list(map(int,input().split())) for _ in range(n)]
querys=[list(map(int,input().split())) for _ in range(k)]

def matrotate(r,c,s):
    for i in range(1,s+1):
        linerotate(r,c,i)

def linerotate(r,c,s):
    global mat,n,m,k
    sr,sc=r-1-s,c-1-s
    er,ec=r-1+s,c-1+s
    dir_list=[]
    val_list=[]
    
    for i in range(sc,ec):
        dir_list.append((sr,i))
        val_list.append(mat[sr][i])
    
    for i in range(sr,er):
        dir_list.append((i,ec))
        val_list.append(mat[i][ec])
    
    for i in range(ec,sc,-1):
        dir_list.append((er,i))
        val_list.append(mat[er][i])
    
    for i in range(er,sr,-1):
        dir_list.append((i,sc))
        val_list.append(mat[i][sc])
    
    tmp=val_list.pop()
    val_list=[tmp]+val_list
    
    for dr_dc, val in zip(dir_list,val_list):
        nr,nc=dr_dc[0],dr_dc[1]
        mat[nr][nc]=val

cases=makeorder(k)
res=[]
for c in cases:
    mat=[i.copy() for i in origin_mat]
    for iter in c:
        matrotate(*querys[iter])
    res.append(min([sum(i) for i in mat]))
print(min(res))