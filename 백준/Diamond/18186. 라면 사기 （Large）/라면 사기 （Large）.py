import sys

def solve():
    input = sys.stdin.readline
    N, B, C = map(int, input().split())
    A = list(map(int, input().split()))
    if B <= C:
        print(sum(A) * B)
        return
    A.append(0)
    A.append(0)
    
    total_cost = 0
    
    for i in range(N):
        if A[i] == 0:
            continue
            
        if A[i+1] > A[i+2]:
            count2 = min(A[i], A[i+1] - A[i+2])
            
            total_cost += count2 * (B + C)
            A[i] -= count2
            A[i+1] -= count2

            count3 = min(A[i], min(A[i+1], A[i+2]))
            
            total_cost += count3 * (B + 2*C)
            A[i] -= count3
            A[i+1] -= count3
            A[i+2] -= count3
            
        else:
            count3 = min(A[i], min(A[i+1], A[i+2]))
            
            total_cost += count3 * (B + 2*C)
            A[i] -= count3
            A[i+1] -= count3
            A[i+2] -= count3
            
            count2 = min(A[i], A[i+1])
            
            total_cost += count2 * (B + C)
            A[i] -= count2
            A[i+1] -= count2
            
        total_cost += A[i] * B
    print(total_cost)
solve()