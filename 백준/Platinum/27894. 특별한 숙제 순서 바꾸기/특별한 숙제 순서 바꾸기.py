n=int(input())
bef=[*map(int,input().split())]
aft=[*map(int,input().split())]
flag=0 if bef!=aft else 1
for i in range(n-2):
    if(aft[i:i+3]==sorted(aft[i:i+3]) or aft[i:i+3]==sorted(aft[i:i+3],reverse=True)):
        flag=1
        break
    
if(flag):print("POSSIBLE")
else:print("IMPOSSIBLE")