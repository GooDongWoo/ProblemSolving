import sys
r,c,k=map(int,sys.stdin.readline().split())
mat=[[0]*100 for _ in range(100)]
for i in range(3):
    mat[i][:3]=list(map(int,sys.stdin.readline().split()))
num_r=3
num_c=3

def R(mat1,rows,cols):
    max_c=0
    for i in range(rows):
        dict1=dict()
        for j in mat1[i][:cols]:
            if j!=0 and not(j in dict1):
                dict1[j]=1
            elif j!=0 and (j in dict1):
                dict1[j]+=1
        l1=sorted([(key,item) for key,item in dict1.items()],key= lambda x: (x[1],x[0]))
        l2=[]
        for key,item in l1:
            l2.extend([key,item])
        if(len(l2)>100):
            mat1[i]=l2[:100]
            max_c=max(max_c,100)
        else:
            mat1[i][:len(l2)]=l2[:len(l2)]
            mat1[i][len(l2):]=[0]*(100-len(l2))
            max_c=max(max_c,len(l2))
    return mat1,rows,max_c

def C(mat1,rows,cols):
    mat1=[list(v) for v in zip(*mat1)]
    mat1,cols,rows=R(mat1,cols,rows)
    mat1=[list(v) for v in zip(*mat1)]
    return mat1,rows,cols

for i in range(102):
    if(mat[r-1][c-1]==k):
        print(i)
        break

    if(num_r>=num_c):
        mat,num_r,num_c=R(mat,num_r,num_c)
    else:
        mat,num_r,num_c=C(mat,num_r,num_c)
    
    if(i==101):
        print(-1)
        break