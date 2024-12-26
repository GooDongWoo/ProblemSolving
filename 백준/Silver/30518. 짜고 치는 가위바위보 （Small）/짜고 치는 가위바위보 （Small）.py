import sys
input = sys.stdin.readline

def F(a1, a2):
    win_s = [('R', 'S'), ('S', 'P'), ('P', 'R')]
    draw_s = [('P', 'P'), ('R', 'R'), ('S', 'S')]
    lose_s = [('S', 'R'), ('P', 'S'), ('R', 'P')]
    if (a1, a2) in win_s:
        return 0
    elif (a1, a2) in draw_s:
        return 1
    else:
        return 2

l = input().rstrip()
s = list(input().rstrip())
MAX = len(s)

dp = [[0] * 3 for _ in range(MAX)] # lighter do (win, draw, lose)
for i in range(MAX):
    dp[i][F(l, s[i])] = 1

# draw after ligter win -> wrong
for i in range(1, MAX):
    for j in range(i):
        cur_res = F(s[j], s[i])
        if cur_res == 1:
            dp[i][cur_res] += dp[j][1] + dp[j][2]
        else:
            dp[i][cur_res] += sum(dp[j])

print(sum([sum(i) for i in dp]) % (int(1e9) + 7))