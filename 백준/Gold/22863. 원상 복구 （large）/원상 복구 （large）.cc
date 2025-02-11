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

LL N, K, S[MAX], D[MAX], dp[51][MAX], ans[MAX], result[MAX];

int main() {
    fastio;
    cin >> N >> K;
    rep(i, 1, N + 1) cin >> S[i];
    rep(i, 1, N + 1) cin >> D[i];

    rep(i, 1, N + 1) dp[0][i] = D[i];
    rep(i, 1, 51) rep(j, 1, N + 1) dp[i][j] = dp[i - 1][dp[i - 1][j]];

    // ans[i]는 K번 셔플 후 i번째에 있는 카드가 원래 어느 위치에 있었는지를 나타냄
    rep(i, 1, N + 1) {
        LL cur = i;
        LL tmpK = K, idx = 0;
        while (tmpK) {
            if (tmpK & 1) {
                cur = dp[idx][cur];
            }
            idx++;
            tmpK >>= 1;
        }
        ans[cur] = i;
    }

    rep(i, 1, N + 1) result[i] = S[ans[i]];
    rep(i, 1, N + 1) printf("%lld ", result[i]);

    return 0;
}