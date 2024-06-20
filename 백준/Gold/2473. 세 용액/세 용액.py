import sys
inf=int(3e9)
n=int(sys.stdin.readline())
il=sorted(list(map(int,sys.stdin.readline().split())))
res=inf
for start in range(n-2):
    mid=start+1
    end=n-1
    while mid<end:
        sum_my=il[start]+il[mid]+il[end]
        abs_sum=abs(sum_my)
        if(abs_sum<res):
            res=abs_sum
            t_s=start
            t_m=mid
            t_e=end
        if(sum_my>0):
            end-=1
        elif(sum_my<0):
            mid+=1
        else:
            break
print(il[t_s],il[t_m],il[t_e])