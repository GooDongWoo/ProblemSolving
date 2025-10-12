N=int(input())
L=100**N or 1;U=L*100
for C in range(2,5000):
    s=int(C**.5)
    if s*s==C:continue
    k=C**3
    m,d,a=0,1,int(k**.5);a0=a;D,B=a,1;pD,pB=1,0
    while D*D-k*B*B!=1:m=d*a-m;d=(k-m*m)//d;a=(a0+m)//d;pD,D=D,a*D+pD;pB,B=B,a*B+pB
    D1,B1=D,B
    while(A:=B*B*k)<U:
        if L<=A:print(B,C);print(D,1);exit()
        D,B=D1*D+k*B1*B,D1*B+B1*D
print(-1)