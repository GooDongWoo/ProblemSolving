#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, M, S, E, ans = 1e9;
bool v[10000];
vector<vector<pair<int, int>>> adjv;
priority_queue<pair<int, int>> pq;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N >> M;
	adjv.resize(N);
	rep(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		adjv[a].push_back({ c,b });
		adjv[b].push_back({ c,a });
	}
	cin >> S >> E;
	S--; E--;
	pq.push({ 1e9,S });
	while (pq.size()) {
		auto curp = pq.top(); pq.pop();
		int w = curp.first, cur = curp.second;
		if (v[cur]) { continue; }
		v[cur] = true;
		ans = min(ans, w);
		if (cur == E) {
			break;
		}
		for (const auto& nxtp : adjv[cur]) {
			int nw = nxtp.first, nxt = nxtp.second;
			if (v[nxt]) { continue; }
			pq.push({nw,nxt});
		}
	}
	cout << ans;
	return 0;
}