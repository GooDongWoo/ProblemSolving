s1=set(['Never gonna give you up','Never gonna let you down',
'Never gonna run around and desert you',
"Never gonna make you cry",
"Never gonna say goodbye",
"Never gonna tell a lie and hurt you",
"Never gonna stop"])
n=int(input())
flag=0
for _ in range(n):
    t=input().rstrip()
    if(t not in s1):
        flag=1
if flag==0:
    print("No")
else:
    print("Yes")