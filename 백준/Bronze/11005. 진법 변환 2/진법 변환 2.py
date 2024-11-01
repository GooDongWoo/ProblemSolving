import sys
input=sys.stdin.readline

num,base=map(int,input().split())
ans=[]
while num>0:
    char=num%base
    if char>=10:
        ans.append(chr(char-10+ord("A")))
    else:
        ans.append(str(char))
    num//=base
print(''.join(map(str,ans[::-1])))