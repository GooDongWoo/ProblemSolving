words=list(input().rstrip())
cnter=[0]*26
for word in words:
    cnter[ord(word)-ord('A')]+=1

oddcnt=0
oddidx=0
for idx,cnt in enumerate(cnter):
    if cnt&1:
        oddcnt+=1
        oddidx=idx
if(oddcnt>1):
    print("I'm Sorry Hansoo")
else:
    result=''
    if(oddcnt):
        result+=chr(ord('A')+oddidx)
        cnter[oddidx]-=1
    for i in range(25,-1,-1):
        result=(chr(ord('A')+i)*(cnter[i]//2)) + result + (chr(ord('A')+i)*(cnter[i]//2))
    print(result)