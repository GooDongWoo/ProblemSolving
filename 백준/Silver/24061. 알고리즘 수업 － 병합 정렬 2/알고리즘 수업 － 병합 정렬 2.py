import sys
sys.setrecursionlimit(int(5e5))
input=sys.stdin.readline
n,k=map(int,input().split())
l=[*map(int,input().split())]
cnt=0

def merge_sort(p,r): 
    if (p < r):
        q = (p + r) // 2     
        merge_sort(p, q)     
        merge_sort(q + 1, r) 
        merge(p, q, r)     

def merge(p, q, r):
    global l,cnt,k
    i = p 
    j = q + 1 
    tmp=[]
    while (i <= q and j <= r):
        if (l[i] <= l[j]):
            tmp.append(l[i])
            i+=1
        else:
            tmp.append(l[j])
            j+=1
    
    tmp.extend(l[i:q+1])
    tmp.extend(l[j:r+1])
    i = p
    for i in range(p,r+1):
        cnt+=1
        l[i]=tmp[i-p]    
        if(cnt>=k):
            print(*l)
            exit()

merge_sort(0,n-1)
print(-1)