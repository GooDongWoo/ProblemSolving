a=list(input().rstrip())
a.append(' ')
new_a=[]
tmp=[]
flag=0
for i in range(len(a)):
    if not (flag): #not tag
        if(a[i]==' ' or a[i]=='\n'):
            new_a.extend(tmp[::-1])
            new_a.append(a[i])
            tmp=[]
        elif(a[i]=='<'):
            new_a.extend(tmp[::-1])
            new_a.append(a[i])
            tmp=[]
            flag=1
        else:
            tmp.append(a[i])
    else: # in tag
        if(a[i]=='>'):
            flag=0
        new_a.append(a[i])
print("".join(new_a))