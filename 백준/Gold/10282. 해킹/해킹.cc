#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))
using namespace std;

const int INF = 1e9;
const int MAX_N = 10005;

vector<pair<int, int>> adj[MAX_N];
int dist[MAX_N];

void solve() {
    int N, D, C;
    cin >> N >> D >> C;
    C--; 

    rep(i, 0, N) {
        adj[i].clear();
        dist[i] = INF;
    }

    rep(i, 0, D) {
        int a, b, s;
        cin >> a >> b >> s;
        a--; b--;
        adj[b].push_back({ s, a });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[C] = 0;
    pq.push({ 0, C });

    while (!pq.empty()) {
        int cw = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cw) continue;

        for (const auto& edge : adj[cur]) {
            int time = edge.first;
            int next_node = edge.second;
            int next_dist = cw + time;

            if (dist[next_node] > next_dist) {
                dist[next_node] = next_dist;
                pq.push({ next_dist, next_node });
            }
        }
    }

    int cnt = 0;
    int max_time = 0;
    rep(i, 0, N) {
        if (dist[i] != INF) {
            cnt++;
            if (dist[i] > max_time) max_time = dist[i];
        }
    }
    cout << cnt << ' ' << max_time << '\n';
}

int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}