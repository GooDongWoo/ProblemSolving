#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <numeric>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX 1000001

LL N, K, S[MAX], D[MAX], rev_D[MAX], dp[60][MAX], ans[MAX], result[MAX];

int main() {
    fastio;
    cin >> N >> K;
    rep(i, 1, N + 1) cin >> S[i];
    rep(i, 1, N + 1) {
        cin >> D[i];
        rev_D[D[i]] = i;  // 역방향 매핑 추가
    }

    // dp[i][j]: 2^i번 역방향으로 이동했을 때의 위치
    rep(i, 1, N + 1) dp[0][i] = rev_D[i];
    rep(i, 1, 60) rep(j, 1, N + 1) dp[i][j] = dp[i - 1][dp[i - 1][j]];

    rep(i, 1, N + 1) ans[i] = i;
    rep(i, 1, N + 1) {
        LL tmpK = K, idx = 0;
        while (tmpK) {
            if (tmpK & 1) {
                ans[i] = dp[idx][ans[i]];
            }
            idx++;
            tmpK >>= 1;
        }
    }

    rep(i, 1, N + 1) result[i] = S[ans[i]];
    rep(i, 1, N + 1) printf("%lld ", result[i]);

    return 0;
}