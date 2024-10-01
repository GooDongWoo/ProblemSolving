word=input().rstrip()
tt=len(word)
l=0
r=tt-1
flag=1
for i in range(tt//2):
    if(word[l]==word[r]):
        l+=1
        r-=1
    else:
        flag=0
        break
if(flag):print(1)
else:print(0)