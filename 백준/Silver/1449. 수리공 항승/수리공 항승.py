n,l=map(int,input().split())
spots=sorted([*map(int,input().split())])
cnt=1
tape_start=spots[0]-0.5
for spot in spots[1:]:
    if(spot<tape_start+l):
        pass
    else:
        cnt+=1
        tape_start=spot-0.5
print(cnt)