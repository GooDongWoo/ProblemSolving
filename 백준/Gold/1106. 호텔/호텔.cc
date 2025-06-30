#define rep(i, a, b) for(int i = a; i < b; ++i)
#include <iostream>
#include <algorithm>
using namespace std;

int C, N, dp[21][1100];

int main() {
    cin >> C >> N;
    int cost, p, ans = 1e9;
    
    rep(i, 0, N + 1) {
        rep(j, 1, 1100) {
            dp[i][j] = 1e9;
        }
    }
    
    rep(i, 1, N + 1) {
        cin >> cost >> p;
        rep(j, 0, 1100) {
            dp[i][j] = dp[i-1][j];
            
            // 현재 도시를 사용하는 경우
            if (j >= p && dp[i][j - p] < 1e9) {
                dp[i][j] = min(dp[i][j], dp[i][j - p] + cost);
            }
            
            if (j >= C) {
                ans = min(ans, dp[i][j]);
            }
        }
    }
    
    printf("%d\n", ans);
    return 0;
}