n=int(input())
l=sorted([*map(int,input().split())])
tot=sum(l)
rest=tot%n
avg_l=[0]*n
if(rest):
    avg_l[-rest:]=[1]*rest
else:
    pass
res=[abs(l[i]-avg_l[i]-tot//n) for i in range(n)]
print(sum(res)//2)