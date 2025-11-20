n = int(input())
word = input().strip()
a=0;
b=0;
for i in range(len(word)):
    if(word[i]=="A"):
        a+=1;
    else:
        b+=1;
if(a>b):
    print("A")
elif(a==b):
    print("Tie")
else:
    print("B")