n=int(input())
for _ in range(n):
    word=list(input().rstrip())
    dict1=dict()
    idx=0
    normal_flag=1
    while idx<len(word):
        if (word[idx] in dict1):
            dict1[word[idx]]+=1
        else:
            dict1[word[idx]]=1
        
        if dict1[word[idx]]==3 and (idx==(len(word)-1) or idx<(len(word)-1) and word[idx]!=word[idx+1]):
            dict1[word[idx]]=0
            normal_flag=0
            break
        elif(dict1[word[idx]]==3 and idx<(len(word)-1) and word[idx]==word[idx+1]):
            dict1[word[idx]]=0
            idx+=1
        idx+=1
        
    if not (normal_flag):
        print('FAKE')
    else:
        print('OK')