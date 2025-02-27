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
LL dists[100000], dist;
vector<vector<pair<int,int>>> adjv(100000);

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
    int a, b, c;
    rep(i, 0, N - 1) {
        cin >> a >> b >> c; a--; b--;
        adjv[a].push_back({ c,b });
        adjv[b].push_back({ c,a });
    }
    queue<int> q;
    q.push(0);
    v[0] = 1;
    dists[0] = 0;
    while (q.size()) {
        int cur = q.front();q.pop();
        rep(i, 0, adjv[cur].size()) {
            int nxt = adjv[cur][i].se;
            if (v[nxt]) continue;
            v[nxt] = 1;
            dists[nxt] = dists[cur] + adjv[cur][i].fi;
            lev[nxt] = lev[cur] + 1;
            p[nxt] = cur;
            q.push(nxt);
        }
    }
    rep(i, 0, N) dp[0][i] = p[i];
    rep(i, 1, 17) rep(j, 0, N) dp[i][j] = dp[i - 1][dp[i - 1][j]];
    cin >> M;
    rep(i, 0, M) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            cin >> a >> b; a--; b--;
            dist = 0;
            if (lev[a] != lev[b]) {
                if (lev[a] > lev[b]) swap(a, b);
                int nb = makeSame(b, lev[a]);
                dist += dists[b] - dists[nb];
                b = nb;
            }
            int lca = LCA(a, b);
            dist += (dists[a] - dists[lca]) + (dists[b] - dists[lca]);
            printf("%lld\n", dist);
        }
        else {
            cin >> a >> b >> c; a--; b--;c--;
            int left = 0, right = 0, na, nb;
            if (a == b) {
                printf("%d\n", a + 1);
                continue;
            }
            na = a; nb = b;
            if (lev[na] != lev[nb]) {
                if (lev[na] > lev[nb]) {
                    left += lev[na] - lev[nb];
                    na = makeSame(na, lev[nb]);
                }
                else {
                    right += lev[nb] - lev[na];
                    nb = makeSame(nb, lev[na]);
                }
            }
            int lca = LCA(na, nb);
            left += lev[na] - lev[lca];
            right += lev[nb] - lev[lca];
            int target;
            if (c <= left) {// find in left
                //a에서 c번 위로 올라간다.
                target = a;
                rep(i, 0, 17) {
                    if (c & (1 << i)) target = dp[i][target];
                }
            }
            else {// find in right
                //b에서 (lev[b]-(c-lev[a]))번 위로 올라간다.
                target = b;
                int num = (lev[b] - lev[lca]) - (c - (lev[a] - lev[lca]));
                rep(i, 0, 17) {
                    if (num & (1 << i)) target = dp[i][target];
                }
            }
            printf("%d\n", target + 1);
        }
    }
    return 0;
}