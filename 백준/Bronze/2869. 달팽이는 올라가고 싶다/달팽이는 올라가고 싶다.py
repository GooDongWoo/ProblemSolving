A, B, V = map(int,input().split())
height=0
day=1
tmp=(V-A)/(A-B)
if(tmp!=int(tmp)):
    tmp=int(tmp)+1
day+=tmp
print(int(day))