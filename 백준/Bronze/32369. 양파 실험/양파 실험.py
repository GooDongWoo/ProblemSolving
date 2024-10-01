n,a,b=map(int,input().split())
y1=1;y2=1
for i in range(n):
    y1+=a
    y2+=b
    
    if(y1<y2):
        y1,y2=y2,y1
    elif(y1==y2):
        y2-=1

print(y1,y2)