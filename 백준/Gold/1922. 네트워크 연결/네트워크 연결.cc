#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int N, M, cost;
vector<vector<pair<int, int>>> adjv;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
bool v[1000];


int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> N >> M;
	adjv.resize(N);
	rep(i, 0, M) {
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		adjv[a].push_back({ w,b });
		adjv[b].push_back({ w,a });
	}
	pq.push({ 0,0 });
	while (pq.size()) {
		auto curp = pq.top(); pq.pop();
		int cur = curp.second;
		int w = curp.first;
		if (v[cur]) {
			continue;
		}
		v[cur] = 1;
		cost += w;
		for (const auto& nxtp : adjv[cur]) {
			int nxt = nxtp.second;
			int nxtw = nxtp.first;
			if (v[nxt]) {
				continue;
			}
			pq.push({ nxtw,nxt });
		}
	}
	cout << cost;
	return 0;
}