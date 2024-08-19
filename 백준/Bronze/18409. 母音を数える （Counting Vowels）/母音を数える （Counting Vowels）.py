_=input()
a=input().rstrip()
list1=['a','e','i','o','u']
cnt=0
for i in a:
    if i in list1:
        cnt+=1
print(cnt)
