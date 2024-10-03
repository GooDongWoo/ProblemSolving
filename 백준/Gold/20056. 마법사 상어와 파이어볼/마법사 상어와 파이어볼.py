N,M,K=map(int,input().split())
f=[[[] for _ in range(N)] for _ in range(N)]
dy_dx=[(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]
for _ in range(M):
    r,c,m,s,d=map(int,input().split())
    f[r-1][c-1].append((m,s,d))

def move():
    global N,dy_dx,f
    tmp=[[[] for _ in range(N)] for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if(f[i][j]):
                for m,s,d in f[i][j]:
                    ny,nx=(i+dy_dx[d][0]*s)%N,(j+dy_dx[d][1]*s)%N
                    tmp[ny][nx].append((m,s,d))
    return tmp

def mergesplit():
    global N,dy_dx,f
    tmp=[[[] for _ in range(N)] for _ in range(N)]
    for i in range(N):
        for j in range(N):
            tot_m=0
            tot_s=0
            d_l=[]
            if(len(f[i][j])>=2):
                #merge
                for m,s,d in f[i][j]:
                    tot_m+=m
                    tot_s+=s
                    d_l.append(d)
                #split
                avg_m=tot_m//5
                if(avg_m==0):continue
                avg_s=tot_s//len(d_l)
                eochck=sum([i%2 for i in d_l])
                avg_d=1 if eochck==0 or eochck==len(d_l) else 0
                if(avg_d):
                    for d in [0,2,4,6]:
                        tmp[i][j].append((avg_m,avg_s,d))
                else:
                    for d in [1,3,5,7]:
                        tmp[i][j].append((avg_m,avg_s,d))
            else:
                tmp[i][j]=f[i][j]
    return tmp

for _ in range(K):
    f=move()
    f=mergesplit()

res=0
for i in range(N):
    for j in range(N):
        for m,_,_ in f[i][j]:
            res+=m

print(res)