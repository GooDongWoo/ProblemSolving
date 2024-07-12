a=int(input())
items=list(map(int,input().split()))
ac=[0]*2
for i in items:
    ac[i&1]+=1
print('Sad') if ac[1] >= ac[0] else print('Happy')