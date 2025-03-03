a, b = map(int, input().split())
res = 1 if a*(100-b)/100<100 else 0
print(res)
