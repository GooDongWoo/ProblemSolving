a=input().rstrip()
cnt=0
ll=['a', 'e', 'i', 'o', 'u']
for i in a:
    if i in ll:
        cnt+=1
print(cnt)