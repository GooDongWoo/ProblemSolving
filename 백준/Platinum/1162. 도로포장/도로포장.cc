#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

struct Item {
	LL val, aft, k;
	bool operator>(const Item& b) const {
		return val > b.val;
	}
};
LL N, M, K, dist[21][10000];
vector<vector<pair<int, int>>> adjv;
priority_queue<Item, vector<Item>, greater<>> pq;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> K;
	adjv.resize(N);
	rep(j, 0, K + 1) {
		rep(i, 0, N) {
			dist[j][i] = 1e18;
		}
	}
	rep(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		adjv[a - 1].push_back({ b - 1 ,c });
		adjv[b - 1].push_back({ a - 1 ,c });
	}
	pq.push({ 0,0,0 });
	while (pq.size()) {
		auto curp = pq.top(); pq.pop();
		LL cv = curp.val, cur = curp.aft, ck = curp.k;
		if (dist[ck][cur] <= cv) {
			continue;
		}
		dist[ck][cur] = cv;
		for (const auto& x : adjv[cur]) {
			int nxt = x.first;
			int w = x.second;
			if (cv + w < dist[ck][nxt]) {
				pq.push({ cv + w ,nxt,ck });
			}
			if (ck < K && cv < dist[ck + 1][nxt]) {
				pq.push({ cv,nxt,ck + 1 });
			}
		}
	}
	LL ans = 1e18;
	rep(i, 0, K + 1) {
		ans = min(ans, dist[i][N - 1]);
	}
	cout << ans;
	return 0;
}