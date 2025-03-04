#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 10007
int N, dp[53][53], ans;

int main() {
    fastio;
    dp[0][0] = 1;
    rep(i, 1, 53) {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    rep(i, 1, 53) rep(j, 1, i) {
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
    }
    cin >> N;
    int cnter = N / 4;
    rep(i, 1, cnter + 1) {
        // 포카드가 i개 있는 경우
        // (13)C(i) * ((52-(4*i)))C(N-(4*i))
        if (i & 1)
            ans = (ans + (dp[13][i]) * (dp[52 - (4 * i)][N - (4 * i)])) % MOD;
        else
            ans = ((ans - (dp[13][i]) * (dp[52 - (4 * i)][N - (4 * i)])) % MOD + MOD) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}