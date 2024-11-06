import sys
input=sys.stdin.readline

idx=1
while 1:
    word=input().rstrip()
    if(word[0]=='-'):break
    cnt=0
    stack=[]
    if word[0]=='}':
        cnt+=1
    stack.append('{')
    for i in range(1,len(word)):
        if((not stack) and word[i]=='}'):
            stack.append('{')
            cnt+=1
        elif word[i]=='}' and stack and stack[-1]=='{':
            stack.pop()
            continue
        else:
            stack.append(word[i])
    if(stack):
        cnt+=len(stack)//2
    print(f"{idx}. {cnt}")
    idx+=1