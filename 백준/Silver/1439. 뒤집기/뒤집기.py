A=list(input().rstrip())
flag=0
cur=A[0]
for i in range(1,len(A)):
    if(A[i]!=cur):
        flag+=1
        cur=A[i]
print(int(flag/2 +.5))