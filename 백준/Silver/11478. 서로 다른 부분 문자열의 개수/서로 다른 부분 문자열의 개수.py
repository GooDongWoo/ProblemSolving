import sys
input=sys.stdin.readline

word=input().strip()
n=len(word)
s=list()
for i in range(n):
    for j in range(i+1,n+1):
        s.append(word[i:j])
s=set(s)
print(len(s))