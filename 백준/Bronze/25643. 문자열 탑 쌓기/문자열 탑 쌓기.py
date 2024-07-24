n,m=map(int,input().split())
words=[input().rstrip() for _ in range(n)]
p_flag=1
for i in range(1,n):
    p_flag=0
    for j in range(m):#
        if(words[i][-(j+1):]==words[i-1][:j+1]):
            p_flag=1
            break
    if(p_flag==0):
        for j in range(m):
            if(words[i-1][-(j+1):]==words[i][:j+1]):
                p_flag=1
                break
    if(p_flag==0):
        break
if(p_flag==0):
    print(0)
else:
    print(1)