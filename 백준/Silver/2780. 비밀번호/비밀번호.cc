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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

#define MOD 1234567
int T, N, dp[1001][10], ans[1001], pan[4][3];
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
vector<vector<int>> adjv(10);

bool chck(int y, int x) {
    if (y == 3) return (x == 0);
    else return(0 <= y && y < 3 && 0 <= x && x < 3);
}

int main() {
    fastio;
    rep(i, 0, 3)rep(j, 0, 3)pan[i][j] = 3 * i + j + 1;
    pan[3][0] = 0;
    rep(i, 0, 3)rep(j, 0, 3) {
        rep(dd, 0, 4) {
            int ny, nx;
            ny = i + dys[dd];
            nx = j + dxs[dd];
            if (!chck(ny, nx)) continue;
            adjv[pan[i][j]].push_back(pan[ny][nx]);
        }
    }
    adjv[0].push_back(7);

    rep(i, 0, 10) dp[1][i] = 1;
    ans[1] = 10;
    rep(i, 2, 1001) {
        rep(j, 0, 10) {
            rep(k, 0, adjv[j].size())
                dp[i][j] = (dp[i][j] + dp[i - 1][adjv[j][k]]) % MOD;
            ans[i] = (ans[i] + dp[i][j]) % MOD;
        }
    }
    cin >> T;
    rep(test_case, 1, T + 1) {
        cin >> N;
        printf("%d\n",ans[N]);
    }

    return 0;
}