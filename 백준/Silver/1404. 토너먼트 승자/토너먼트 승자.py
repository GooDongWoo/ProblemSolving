import sys
input=sys.stdin.readline
n=8
l=list(map(int,input().split()))
adj_m=[[0]*n for _ in range(n)]
row=0
idx=0
for i in range(n-1,0,-1):
    for j in range(n-i,n):
        adj_m[row][j]=l[idx]/100
        adj_m[j][row]=(100-l[idx])/100
        idx+=1
    row+=1

res=[0]*8

res=[]
tmp=[0]*7
def bt(idx):
    if(idx==7):
        res.append(tmp.copy())
    else:
        for i in range(2):
            tmp[idx]=i
            bt(idx+1)
bt(0)

ans=[0]*n
for sim in res:
    prob=1
    if sim[0]:
        l1=0;prob*=adj_m[0][1]
    else:
        l1=1;prob*=adj_m[1][0]
        
    if sim[1]:
        l2=2;prob*=adj_m[2][3]
    else:
        l2=3;prob*=adj_m[3][2]
        
    if sim[2]:
        r1=4;prob*=adj_m[4][5]
    else:
        r1=5;prob*=adj_m[5][4]
    
    if sim[3]:
        r2=6;prob*=adj_m[6][7]
    else:
        r2=7;prob*=adj_m[7][6]
        
    if sim[4]:
        f1=l1;prob*=adj_m[l1][l2]
    else:
        f1=l2;prob*=adj_m[l2][l1]
    
    if sim[5]:
        f2=r1;prob*=adj_m[r1][r2]
    else:
        f2=r2;prob*=adj_m[r2][r1]
    
    if sim[6]:
        winner=f1;prob*=adj_m[f1][f2]
    else:
        winner=f2;prob*=adj_m[f2][f1]
    ans[winner]+=prob

print(*ans)