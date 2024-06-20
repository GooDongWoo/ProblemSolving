import sys
from bisect import bisect_left as bisec
inf=int(1e10)
n=int(sys.stdin.readline())
il=list(map(int,sys.stdin.readline().split()))
zdx=bisec(il,0)
res=inf
start=0
end=n-1
t_s,t_e=-1,-1
if(zdx+1<n):
    sum_my=il[zdx]+il[zdx+1]
    if(abs(sum_my)<res):
        res=abs(sum_my)
        t_s=zdx
        t_e=zdx+1

if(zdx-2>=0):
    sum_my=il[zdx-2]+il[zdx-1]
    if(abs(sum_my)<res):
        res=abs(sum_my)
        t_s=zdx-2
        t_e=zdx-1

while start<end and start<zdx and end>=zdx:
    sum_my=il[start]+il[end]
    if(abs(sum_my)<res):
        res=abs(sum_my)
        t_s=start
        t_e=end
    if(sum_my>0):
        end-=1
    elif(sum_my<0):
        start+=1
    else:
        break
print(il[t_s],il[t_e])