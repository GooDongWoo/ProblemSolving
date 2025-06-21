n = int(input())
l = [1000, 5000, 10000, 50000]
ans = 0
for _ in range(n):
    a,b = map(int, input().split())
    a -=136
    a //= 6
    ans += l[a]
print(ans)
    
    