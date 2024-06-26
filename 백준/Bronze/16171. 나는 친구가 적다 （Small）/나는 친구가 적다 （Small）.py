a=input().rstrip()
b=input().rstrip()
tmp=''
for i in range(len(a)):
    if(a[i].isalpha()):
        tmp+=a[i]
if(b in str(tmp)):
    print(1)
else:
    print(0)