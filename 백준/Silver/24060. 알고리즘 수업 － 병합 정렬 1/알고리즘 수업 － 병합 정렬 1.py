import sys
input=sys.stdin.readline

def merge_sort(A, p, r):
    if p < r:
        q = (p + r) // 2
        merge_sort(A, p, q)
        merge_sort(A, q + 1, r)
        merge(A, p, q, r)
        
def merge(A, p, q, r):
    global cnt,tmp
    i = p
    j = q + 1
    t = 0
    while i <= q and j <= r:
        if A[i] <= A[j]:
            tmp[t] = A[i]
            t += 1
            i += 1
        else:
            tmp[t] = A[j]
            t += 1
            j += 1
    while i <= q:
        tmp[t] = A[i]
        t += 1
        i += 1
    while j <= r:
        tmp[t] = A[j]
        t += 1
        j += 1
    i = p
    t = 0
    while i <= r:
        cnt+=1
        if(cnt==k):
            print(tmp[t])
        A[i] = tmp[t]
        i += 1
        t += 1

n,k = map(int,input().split())
A = list(map(int, input().split()))
tmp = [0] * (n)
cnt=0
merge_sort(A, 0, n-1)
if cnt<k:
    print(-1)