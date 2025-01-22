import sys
input = sys.stdin.readline
 
def gcd(a, b):
    max1, min1 = max(a,b), min(a,b)
    if (max1 % min1 == 0):return min1
    return gcd((max1 % min1), min1)

def lcm(a, b):
    return a * b // gcd(a, b)

LIMIT = int(1e6)
while 1:
    m, n = map(int, input().split())
    if (m == 0 and n ==0): break
    nm, nn = m, n
    ans = []
    while nm != 0:
        sub_div = nn // nm if nn % nm == 0 else nn // nm + 1
        flag = 0
        while not flag:
            new_down = lcm(sub_div, nn)
            new_up = nm * (new_down // nn) - (new_down // sub_div)
            if new_up:
                tmp_div = gcd(abs(new_down), abs(new_up))
                new_up //= tmp_div
                new_down //= tmp_div
            if new_down >= LIMIT:
                sub_div += 1
            else:
                flag = 1
                ans.append(sub_div)
                nm, nn = new_up, new_down
    print(*ans)