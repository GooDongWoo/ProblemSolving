import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e4))

def compare_array(A):
    global flag, B
    for i in range(len(A)):
        if A[i] != B[i]:
            return False
    flag = 1
    return True

def swap(A, i, j):
    A[i], A[j] = A[j], A[i]

def partition(A, left, right):
    lo = left
    hi = right
    pivot = A[right]
    
    while lo < hi:
        # lo의 요소가 pivot보다 큰 값을 먼저 찾기
        while lo < hi and A[lo] < pivot:
            lo += 1
            
        while lo < hi and A[hi] >= pivot:
            hi -= 1
            
        swap(A, lo, hi)
        compare_array(A)  # 스왑할 때마다 B배열과 비교
    
    swap(A, hi, right)
    compare_array(A)
    return hi

def quick_sort(A, left, right):
    global flag
    if left >= right:
        return
    if flag == 1:
        return
        
    pivot = partition(A, left, right)
    
    quick_sort(A, left, pivot - 1)
    quick_sort(A, pivot + 1, right)

# 입력 처리
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
flag = 0

compare_array(A)
quick_sort(A, 0, N - 1)

print(flag)