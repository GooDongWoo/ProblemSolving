a=list(input().rstrip())
b=[]
for i in a:
    if(i.isupper()):
        b.append(i.lower())
    else:
        b.append(i.upper())
print(*b,sep='')