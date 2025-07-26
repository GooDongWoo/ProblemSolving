#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const int INF = INT_MAX;

struct Node {
	int dest, cost, time;
};
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;

	int N, M, K;
	cin >> N >> M >> K;

	vector<vector<Node>> adj(N + 1); // {destination, cost, time}
	vector<vector<int>> dp(N + 1, vector<int>(M + 1, INF));

	rep(i, 0, K) {
		int u, v, c, d;
		cin >> u >> v >> c >> d;
		adj[u].push_back({ v, c, d });
	}

	dp[1][0] = 0;
	rep(cost, 0, M + 1) {
		rep(node, 1, N + 1) {
			if (dp[node][cost] < INF) {
				for (auto& edge : adj[node]) {
					int nxt = edge.dest;
					int ncost = edge.cost;
					int ntime = edge.time;

					int totalCost = cost + ncost;
					int totalTime = dp[node][cost] + ntime;

					if (totalCost <= M && totalTime < dp[nxt][totalCost]) {
						dp[nxt][totalCost] = totalTime;
					}
				}
			}
		}
	}
	int answer = INF;
	rep(cost, 0, M + 1) {
		answer = min(answer, dp[N][cost]);
	}

	if (answer == INF) {
		cout << "Poor KCM";
	}
	else {
		cout << answer;
	}

	return 0;
}