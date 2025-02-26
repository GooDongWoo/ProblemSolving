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
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

int N, M, dp[17][100000], p[100000], v[100000], lev[100000];
vector<vector<int>> adjv(100000);

int LCA(int a, int b) {
    while (a != b) {
        int start, end;
        start = 0;
        end = 16;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (dp[mid][a] == dp[mid][b]) end = mid - 1;
            else start = mid + 1;
        }
        end = max(end, 0);
        a = dp[end][a];
        b = dp[end][b];
    }
    return a;
}
int makeSame(int target, int tlv) {
    int num = lev[target] - tlv;
    rep(i, 0, 17) {
        if (num & (1 << i)) target = dp[i][target];
    }
    return target;
}
int main() {
    fastio;
    cin >> N;
    int a, b;
    rep(i, 0, N - 1) {
        cin >> a >> b; a--; b--;
        adjv[a].push_back(b);
        adjv[b].push_back(a);
    }
    queue<int> q;
    q.push(0);
    v[0] = 1;
    while (q.size()) {
        int cur = q.front();q.pop();
        rep(i, 0, adjv[cur].size()) {
            int nxt = adjv[cur][i];
            if (v[nxt]) continue;
            v[nxt] = 1;
            lev[nxt] = lev[cur] + 1;
            q.push(nxt);
            p[nxt] = cur;
        }
    }
    rep(i, 0, N) dp[0][i] = p[i];
    rep(i, 1, 17) rep(j, 0, N) dp[i][j] = dp[i - 1][dp[i - 1][j]];
    cin >> M;
    rep(i, 0, M) {
        cin >> a >> b; a--; b--;
        if (lev[a] != lev[b]) {
            if (lev[a] > lev[b]) swap(a, b);
            b = makeSame(b, lev[a]);
        }
        printf("%d\n", LCA(a, b)+1);
    }
    return 0;
}