import sys
input=sys.stdin.readline

t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    i_part = a // b
    newa = (a - (b * i_part))
    s1 = []
    ans =f'{i_part}.'
    while 1:
        newa *= 10
        if newa in s1:
            dot_idx = ans.index('.')
            idx = s1.index(newa)
            tmp = ans[dot_idx + 1 + idx:]
            tmp = '('+ tmp +')'
            ans = ans[:dot_idx + 1 + idx] + tmp
            break
        else: s1.append(newa)
        ans += str(newa // b)
        newa %= b
    sys.stdout.write(f'{ans}\n')