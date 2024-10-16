import sys
sys.setrecursionlimit(int(5e5))
input=sys.stdin.readline
n,k=map(int,input().split())
l=[*map(int,input().split())]
cnt=0
def quick_sort(p,r):
    if (p < r):
        q=partition(p, r);  # 분할
        quick_sort(p, q - 1);  # 왼쪽 부분 배열 정렬
        quick_sort(q + 1, r);  # 오른쪽 부분 배열 정렬

def partition(p, r):
    global l,k,cnt
    x = l[r]    # 기준원소
    i = p - 1   # i는 x보다 작거나 작은 원소들의 끝지점
    for j in range(p,r):# j는 아직 정해지지 않은 원소들의 시작 지점
        if (l[j] <= x):
            i+=1
            l[i],l[j]=l[j],l[i]; # i값 증가 후 A[i] <-> A[j] 교환
            cnt+=1
            if(cnt==k):
                print(*sorted([l[i],l[j]]))
                exit()
    if (i + 1 != r): 
        l[i + 1],l[r]=l[r],l[i + 1] # i + 1과 r이 서로 다르면 A[i + 1]과 A[r]을 교환
        cnt+=1
        if(cnt==k):
            print(*sorted([l[r],l[i + 1]]))
            exit()
    return i + 1
quick_sort(0,n-1)
print(-1)