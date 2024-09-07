while 1:
    sentence=input().rstrip()
    if(sentence=='#'):break
    l1=set(['a', 'e', 'i', 'o', 'u'])
    sentence=sentence.lower()
    cnt=0
    for i in range(len(sentence)):
        if(sentence[i] in l1):cnt+=1
    print(cnt)