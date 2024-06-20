import sys
inf=int(1e10)
n=int(sys.stdin.readline())
il=sorted(list(map(int,sys.stdin.readline().split())))
res=inf
start=0
end=n-1
t_s,t_e=-1,-1
while start<end:
    sum_my=il[start]+il[end]
    abs_sum=abs(sum_my)
    if(abs_sum<res):
        res=abs_sum
        t_s=start
        t_e=end
    if(sum_my>0):
        end-=1
    elif(sum_my<0):
        start+=1
    else:
        break
print(il[t_s],il[t_e])