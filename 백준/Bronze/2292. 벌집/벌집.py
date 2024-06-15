n=int(input())
init=1
diff=6
cnt=1

while(1):
    if(n<=init):
        print(cnt)
        break
    else:
        init+=diff
        diff+=6
        cnt+=1