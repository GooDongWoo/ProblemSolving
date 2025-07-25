#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define rep(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;

struct Item {
	int val, bef, aft;
	bool operator>(const Item& b) const {
		return val > b.val;
	}
};
int N, M, dist[1000];
vector<vector<pair<int, int>>> adjv;
priority_queue<Item, vector<Item>, greater<>> pq;
vector<pair<int, int>> ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	adjv.resize(N);
	rep(i, 0, N) {
		dist[i] = 1e9;
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
		int cv = curp.val, cur = curp.aft, bef = curp.bef;
		if (dist[cur] <= cv) {
			continue;
		}
		dist[cur] = cv;
		if (cur != 0) {
			ans.push_back({ bef+1,cur+1 });
		}
		for (const auto& x : adjv[cur]) {
			int nxt = x.first;
			int w = x.second;
			if (cv + w < dist[nxt]) {
				pq.push({ cv + w ,cur,nxt });
			}
		}
	}
	cout << ans.size() << '\n';
	for (const auto& x : ans) {
		cout << x.first << " " << x.second << '\n';
	}
	return 0;
}