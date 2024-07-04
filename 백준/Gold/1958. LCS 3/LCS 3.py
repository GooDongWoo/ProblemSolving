import sys
input = sys.stdin.readline

def get_LCS(w1, w2, w3):
    dp = [[[0]*len(w3) for _ in range(len(w2))] for _ in range(len(w1))]
    
    for i in range(1,len(w1)):
        for j in range(1,len(w2)):
            for k in range(1,len(w3)):
                if w1[i] == w2[j] == w3[k]:
                    dp[i][j][k] = dp[i-1][j-1][k-1]+1
                else:
                    dp[i][j][k] = max(dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1])
        
    return dp[-1][-1][-1]
    

if __name__ == '__main__':
    w1 = ' '+input().strip()
    w2 = ' '+input().strip()
    w3 = ' '+input().strip()
    
    print(get_LCS(w1,w2,w3))
'''import sys
a=(sys.stdin.readline().rstrip())
b=(sys.stdin.readline().rstrip())
c=(sys.stdin.readline().rstrip())
dp=[[[0]*(len(a)+1) for _ in range(len(b)+1)]for _ in range(len(c)+1)]
for k in range(1,len(c)+1):
    for i in range(1,len(b)+1):
        for j in range(1,len(a)+1):
            if((a[j-1]==b[i-1]==c[k-1])):
                dp[k][i][j]=dp[k-1][i-1][j-1]+1
            else:
                dp[k][i][j]=max(dp[k][i][j-1],dp[k][i-1][j],dp[k-1][i][j])
sys.stdout.write(f'{dp[-1][-1][-1]}')'''