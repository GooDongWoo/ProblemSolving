words=list(input().rstrip())
length=len(words)
cnt=0
idx=0
while idx<length:
    cnt+=1
    if(idx+1<length and words[idx]=='c' and (words[idx+1]=='=' or words[idx+1]=='-')):
        idx+=2
    
    elif(idx+2<length and words[idx]=='d' and words[idx+1]=='z' and words[idx+2]=='='):
        idx+=3
        
    elif(idx+1<length and words[idx]=='d' and words[idx+1]=='-'):
        idx+=2
    
    elif(idx+1<length and words[idx]=='l' and words[idx+1]=='j'):
        idx+=2
    
    elif(idx+1<length and words[idx]=='n' and words[idx+1]=='j'):
        idx+=2
    
    elif(idx+1<length and words[idx]=='s' and words[idx+1]=='='):
        idx+=2
    
    elif(idx+1<length and words[idx]=='z' and words[idx+1]=='='):
        idx+=2
    else:
        idx+=1
print(cnt)
