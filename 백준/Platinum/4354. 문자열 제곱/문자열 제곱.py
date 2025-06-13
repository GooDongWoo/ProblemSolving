import sys
input = sys.stdin.readline

while True:
    arr = input().rstrip()
    if arr == '.':
        break
    N = len(arr)
    Flag = 0
    for i in range(1, (N // 2) + 1):
        if N % i:
            continue
        if arr[:i] * (N // i) == arr:
            print(N // i)
            Flag = 1
            break
    if not Flag:
        print(1)