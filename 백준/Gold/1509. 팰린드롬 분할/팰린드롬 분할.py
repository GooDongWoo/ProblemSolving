import sys
input = sys.stdin.readline

INF = int(1e9)
word = input().rstrip()
n = len(word)
chck = [[0]*n for _ in range(n)]
for i in range(n):chck[i][i] = 1
for i in range(n-1):
    chck[i][i+1] = 1 if word[i] == word[i+1] else 0

for l in range(2, n):
    for i in range(n):
        if not(i+l < n): break
        chck[i][i+l] = 1 if (chck[i+1][i+l-1] and word[i] == word[i+l]) else 0

dp = [INF] * n
dp[0] = 1
for j in range(1, n): # j까지의 최소 분할 횟수
    for i in range(j+1): # 만약 i부터 펠린드롬이면 i-1까지의 횟수 + 1 
        if (chck[i][j]):
            if i == 0:dp[j] = 1;break
            else:dp[j] = min(dp[j], dp[i-1]+1)

print(dp[-1])