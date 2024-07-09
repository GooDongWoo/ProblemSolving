n=int(input())
words=[list(input().rstrip()) for _ in range(n)]
cnt=0
for word in words:
    chcker=[0]*26
    idx=0
    no_flag=0
    while idx<len(word):
        if(chcker[ord(word[idx])-ord('a')]==1):
            no_flag=1
            break
        tmp=word[idx]
        chcker[ord(word[idx])-ord('a')]=1
        while idx<len(word)-1 and word[idx+1]==tmp:
            idx+=1
        idx+=1
    if(not no_flag):
        cnt+=1
print(cnt)