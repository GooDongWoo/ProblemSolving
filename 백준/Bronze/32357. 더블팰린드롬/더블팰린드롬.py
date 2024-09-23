n=int(input())
cnt=0
for _ in range(n):
    word=input().rstrip()
    l=len(word)
    if(word[:l//2]==word[l-1:l//2-1:-1]):
        cnt+=1
print(cnt*(cnt-1))