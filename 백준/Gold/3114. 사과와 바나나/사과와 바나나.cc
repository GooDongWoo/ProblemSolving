#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define LL long long
const int MAX_SIZE = 1502;
LL R, C;
LL lsum[MAX_SIZE][MAX_SIZE] = {0}; 
LL rsum[MAX_SIZE][MAX_SIZE] = {0}; 
LL dp[2][MAX_SIZE][MAX_SIZE] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    
    cin >> R >> C;
    
    string tmp;
    rep(i, 1, R + 1) {
        rep(j, 1, C + 1) {
            cin >> tmp;
            if (tmp[0] == 'A') 
                lsum[i][j] = stoi(tmp.substr(1));
            else 
                rsum[i][j] = stoi(tmp.substr(1));
        }
    }
    
    rep(i, 1, R + 1) {
        rep(j, 2, C + 1) {
            lsum[i][j] += lsum[i][j - 1];
            rsum[i][C - j + 1] += rsum[i][C - j + 2];
        }
    }
    
    dp[1][1][1] = rsum[1][2];
    
    for (int j = 2; j <= C; j++) {
        LL diff = rsum[1][j] - rsum[1][j + 1];
        dp[1][1][j] = dp[1][1][j - 1] - diff;
    }
    
    // 첫 번째 열 초기화
    for (int i = 2; i <= R; i++) {
        dp[1][i][1] = dp[1][i - 1][1] + rsum[i][2];
    }
    
    for (int i = 2; i <= R; i++) {
        for (int j = 2; j <= C; j++) {
            LL left_apples = lsum[i][j - 1];
            LL right_bananas = rsum[i][j + 1];
            LL curr_banana_diff = rsum[i][j] - rsum[i][j + 1];
            
            LL a_total = dp[0][i-1][j] + left_apples + dp[1][i-1][j] + right_bananas;
            LL b_total = dp[0][i-1][j-1] + left_apples + dp[1][i-1][j-1] + right_bananas;
            LL c_total = dp[0][i][j-1] + dp[1][i][j-1] - curr_banana_diff;
            
            if (a_total >= b_total && a_total >= c_total) {
                dp[0][i][j] = dp[0][i-1][j] + left_apples;
                dp[1][i][j] = dp[1][i-1][j] + right_bananas;
            }
            else if (b_total >= c_total) {
                dp[0][i][j] = dp[0][i-1][j-1] + left_apples;
                dp[1][i][j] = dp[1][i-1][j-1] + right_bananas;
            }
            else {
                dp[0][i][j] = dp[0][i][j-1];
                dp[1][i][j] = dp[1][i][j-1] - curr_banana_diff;
            }
        }
    }
    
    cout << dp[0][R][C] + dp[1][R][C];
    return 0;
}