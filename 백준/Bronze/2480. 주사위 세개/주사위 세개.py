a,b,c=input().split()
a=int(a)
b=int(b)
c=int(c)
condition=0
condition= (int(a==b)<<2)+(int(a==c)<<1)+int(c==b)
if condition==7:
    print(10000+a*1000)
elif condition>0:
    if condition==4:
        print(1000+a*100)
    elif condition==2:
        print(1000+a*100)
    else:
        print(1000+b*100)
else:
    print(max(a,b,c)*100)