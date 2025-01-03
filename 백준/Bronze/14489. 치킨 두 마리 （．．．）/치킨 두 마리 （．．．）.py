a, b = map(int, input().split())
c = int(input())
res = a + b if a + b < c * 2 else a + b - c * 2
print(res)