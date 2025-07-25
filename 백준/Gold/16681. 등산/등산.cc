#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

struct Item {
	LL val, aft;
	bool operator>(const Item& b) const {
		return val > b.val;
	}
};
LL N, M, dist[2][100000], D, E, H[100000];
vector<vector<pair<int, int>>> adjv;
priority_queue<Item, vector<Item>, greater<>> pq;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> D >> E;
	adjv.resize(N);
	rep(i, 0, N) {
		cin >> H[i];
		dist[0][i] = 1e18;
		dist[1][i] = 1e18;
	}
	rep(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		adjv[a - 1].push_back({ b - 1 ,c });
		adjv[b - 1].push_back({ a - 1 ,c });
	}
	pq.push({ 0,0 });
	while (pq.size()) {
		auto curp = pq.top(); pq.pop();
		LL cv = curp.val, cur = curp.aft;
		if (dist[0][cur] <= cv) {
			continue;
		}
		dist[0][cur] = cv;
		for (const auto& x : adjv[cur]) {
			int nxt = x.first;
			int w = x.second;
			if (cv + w < dist[0][nxt] && H[nxt]>H[cur]) {
				pq.push({ cv + w ,nxt });
			}
		}
	}

	pq.push({ 0,N - 1 });
	while (pq.size()) {
		auto curp = pq.top(); pq.pop();
		LL cv = curp.val, cur = curp.aft;
		if (dist[1][cur] <= cv) {
			continue;
		}
		dist[1][cur] = cv;
		for (const auto& x : adjv[cur]) {
			int nxt = x.first;
			int w = x.second;
			if (cv + w < dist[1][nxt] && H[nxt]>H[cur]) {
				pq.push({ cv + w ,nxt });
			}
		}
	}
	LL ans = -1e18;
	rep(i, 1, N - 1) {
		if (dist[0][i] == 1e18 || dist[1][i] == 1e18) {
			continue;
		}
		ans = max(ans, (H[i] * E) - ((dist[0][i] + dist[1][i]) * D));
	}
	if (ans == -1e18) {
		cout << "Impossible";
	}
	else {
		cout << ans;
	}
	return 0;
}