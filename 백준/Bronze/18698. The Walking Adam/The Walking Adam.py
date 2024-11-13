import sys
input=sys.stdin.readline

n=int(input())
for _ in range(n):
    word=input().rstrip()
    cnt=0
    for i in range(len(word)):
        if word[i]!='D':
            cnt+=1
        else:
            break
    print(cnt)