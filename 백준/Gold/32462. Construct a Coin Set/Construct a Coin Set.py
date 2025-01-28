import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n = int(input())
    if n < 6:
        print("-1")
    elif n % 2 == 1:
        print(4)
        print(1, 3, n - 3, n - 2)
    else:
        print(3)
        print(1, n // 2, n // 2 + 1)
