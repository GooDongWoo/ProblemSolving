a,b=input().split()
a=int(a)
b=int(b)
if b>=45:
    print(str(a)+" "+str(b-45))
else:
    if a==0:
        print(str(23)+" "+str(b+15))
    else:
        print(str(a-1)+" "+str(b+15))