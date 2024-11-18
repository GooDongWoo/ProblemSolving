import sys
input=sys.stdin.readline

n=int(input())
a=[*map(int,input().split())]

m=int(input())
b=[*map(int,input().split())]

tmp_a=a[:]
tmp_b=b[:]
ans=[]
while tmp_a and tmp_b:
    s_a=set(tmp_a)
    s_b=set(tmp_b)
    candidates=sorted(list(s_a & s_b),reverse=True)
    if candidates:
        target=candidates[0]
        ans.append(target)
        aidx=tmp_a.index(target)
        bidx=tmp_b.index(target)
        tmp_a=tmp_a[aidx+1:]
        tmp_b=tmp_b[bidx+1:]
    else:break

print(len(ans))
print(*ans)