import sys
input = sys.stdin.readline

n, k = map(int, input().split())
tmp = n
tmp_str = []
while tmp:
    tmp_str.append(tmp % k)
    tmp //= k

ans = 0
if len(tmp_str) % 2 == 0 :
    ans = k ** (len(tmp_str) // 2) 
else:
    for i in range(len(tmp_str)-1, -1, -2):
        if i != 0:
            if tmp_str[i-1] != 0:
                ans += (k ** (i//2)) * (tmp_str[i] + 1)
                break
            else:
                ans += (k ** (i//2)) * (tmp_str[i])
        else:
            ans += tmp_str[0] + 1
print(ans)