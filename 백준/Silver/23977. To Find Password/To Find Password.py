import sys
input = sys.stdin.readline

def lcm(x, y):
    def gcd(x, y):
        max1, min1 = max(x, y), min(x, y)
        if max1 % min1 == 0:
            return min1
        else:
            return gcd(max1 % min1, min1)
    
    return x * y // gcd(x, y)
        
k, n = map(int, input().split())
a = sorted(list(map(int, input().split())), reverse=True)
tmp = a[0]
for i in range(1, n):
    tmp = lcm(tmp, a[i])

print(tmp - k)