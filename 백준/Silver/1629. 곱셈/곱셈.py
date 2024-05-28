def prod(a,b,c):
    new_b=b//2
    if(b==1):
        return a%c
    if(new_b==b-new_b):
        return ((prod(a,new_b,c)%c)**2)%c
    else:
        t1=prod(a,new_b,c)%c
        t2=prod(a,b-new_b,c)%c
        return (t1*t2)%c

a,b,c=map(int,input().split())
print(prod(a,b,c))