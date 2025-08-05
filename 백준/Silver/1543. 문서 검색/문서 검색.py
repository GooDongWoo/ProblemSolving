origin = input().rstrip()
target = input().rstrip()
tsize = len(target)
osize = len(origin)
ans = 0
idx = 0
while(idx<osize):
    if(origin[idx:idx+tsize] == target):
        ans+=1
        idx+=tsize-1
    idx+=1
print(ans)
