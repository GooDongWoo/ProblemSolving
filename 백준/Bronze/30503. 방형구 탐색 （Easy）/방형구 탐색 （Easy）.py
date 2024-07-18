import sys
n=int(sys.stdin.readline())
mat=[*map(int,sys.stdin.readline().split())]
q=int(sys.stdin.readline())
for _ in range(q):
    query=[*map(int,sys.stdin.readline().split())]
    if(query[0]==1):# print
        l,r=query[1],query[2]
        k=query[3]
        cnt=0
        for i  in range(l-1,r):
            if(mat[i]==k):
                cnt+=1
        sys.stdout.write(f'{cnt}\n')
    else:           # delete
        l,r=query[1],query[2]
        for i  in range(l-1,r):
            mat[i]=0