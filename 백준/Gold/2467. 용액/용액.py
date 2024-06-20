import sys
from bisect import bisect_left as bisec
inf=int(1e10)
n=int(sys.stdin.readline())
il=list(map(int,sys.stdin.readline().split()))
zdx=bisec(il,0)
res=inf
res_1=res_2=0
#--
if(zdx-2>=0):
    if(res>abs(il[zdx-1]+il[zdx-2])):
        res=min(res,abs(il[zdx-1]+il[zdx-2]))
        res_1,res_2=il[zdx-2],il[zdx-1]
#++
if(zdx+1<n):
    if(res>abs(il[zdx]+il[zdx+1])):
        res=min(res,abs(il[zdx]+il[zdx+1]))
        res_1,res_2=il[zdx],il[zdx+1]
#-+
if(1<=zdx<n):
    p_len=n-zdx
    m_len=n-p_len
    if(p_len>m_len):
        #calc every m, find matched +value
        idx=zdx-1
        while idx>=0:
            if(bisec(il,-il[idx])<n and bisec(il,-il[idx])>zdx):
                m_v=min(abs(il[idx]+il[bisec(il,-il[idx])]),abs(il[idx]+il[bisec(il,-il[idx])-1]))
                if abs(il[idx]+il[bisec(il,-il[idx])])<abs(il[idx]+il[bisec(il,-il[idx])-1]):
                    tmp_a,tmp_b=il[idx],il[bisec(il,-il[idx])]
                else:
                    tmp_a,tmp_b=il[idx],il[bisec(il,-il[idx])-1]
                    
            elif(bisec(il,-il[idx])<n and bisec(il,-il[idx])==zdx):
                m_v=abs(il[idx]+il[bisec(il,-il[idx])])
                tmp_a,tmp_b=il[idx],il[bisec(il,-il[idx])]
                pass
            else:
                m_v=abs(il[idx]+il[bisec(il,-il[idx])-1])
                tmp_a,tmp_b=il[idx],il[bisec(il,-il[idx])-1]
            if(res>m_v):
                res=min(res,m_v)
                res_1,res_2=tmp_a,tmp_b
            idx-=1
    else:
        #calc every p, find matched -value
        idx=zdx
        while idx<n:
            if(bisec(il,-il[idx])>0 and bisec(il,-il[idx])<=zdx-1):
                #2
                m_v=min(abs(il[idx]+il[bisec(il,-il[idx])]),abs(il[idx]+il[bisec(il,-il[idx])-1]))
                if abs(il[idx]+il[bisec(il,-il[idx])])<abs(il[idx]+il[bisec(il,-il[idx])-1]):
                    tmp_a,tmp_b=il[idx],il[bisec(il,-il[idx])]  
                else:
                    tmp_a,tmp_b=il[idx],il[bisec(il,-il[idx])-1]
                    
            elif(bisec(il,-il[idx])>0 and bisec(il,-il[idx])==zdx):
                m_v=abs(il[idx]+il[bisec(il,-il[idx])-1])
                tmp_a,tmp_b=il[idx],il[bisec(il,-il[idx])-1]
            else:
                #1
                m_v=abs(il[idx]+il[bisec(il,-il[idx])])
                tmp_a,tmp_b=il[idx],il[bisec(il,-il[idx])]
            if(res>m_v):
                res=min(res,m_v)
                res_1,res_2=tmp_a,tmp_b
            idx+=1
print(*sorted([res_1,res_2]))