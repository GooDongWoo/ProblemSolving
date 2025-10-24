#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define rep(i, a, b) for (int i = a; i < b; ++i)
using LL = long long;
using namespace std;

int N, M, cnter;
vector<vector<int>> adjv[2];
bool v[500];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin >> N >> M;

    adjv[0].resize(N);
    adjv[1].resize(N);

    rep(i, 0, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adjv[0][a].push_back(b);
        adjv[1][b].push_back(a);
    }

    rep(j, 0, N) {
        int cnt[2] = { 0, 0 };
        memset(v, 0, sizeof(v));
        rep(i, 0, 2) {
            queue<int> q;
            q.push(j);
            while (q.size()) {
                int cur = q.front(); q.pop();
                for (const auto nxt : adjv[i][cur]) {
                    if (v[nxt]) {
                        continue;
                    }
                    v[nxt] = true;
                    q.push(nxt);
                    cnt[i]++;
                }
            }
        }
        if (cnt[0] + cnt[1] == N - 1) {
            cnter++;
        }
    }
    cout << cnter;
    return 0;
}