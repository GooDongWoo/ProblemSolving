n=int(input())
items=input().split()
ans='Cheese'
s=set()
for item in items:
    if(len(item)>=6 and item[-6:]==ans):
        s.add("".join(item[:-6]))
if(len(s)>=4):
    print('yummy')
else:
    print('sad')