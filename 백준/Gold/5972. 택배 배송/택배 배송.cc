#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;

using ui = unsigned int;
ui N, M;
ui v[50000];
vector<vector<pair<ui, ui>>> adjv;

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cout.tie(NULL);

	memset(v, -1, sizeof(v));

	cin >> N >> M;
	adjv.resize(N);

	rep(i, 0, M) {
		ui a, b;
		ui w;
		cin >> a >> b >> w;
		a--; b--;
		adjv[a].push_back({ w,b });
		adjv[b].push_back({ w,a });
	}
	priority_queue<pair<ui, ui>, vector<pair<ui, ui>>, greater<>> pq;

	v[0] = 0;
	pq.push({ 0,0 });
	while (pq.size()) {
		auto curp = pq.top(); pq.pop();
		ui cw = curp.first, cur = curp.second;
		if (cw > v[cur]) {
			continue;
		}
		for (const auto& nxtp : adjv[cur]) {
			ui dw = nxtp.first, nxt = nxtp.second;
			if (v[cur] + dw >= v[nxt]) {
				continue;
			}
			v[nxt] = v[cur] + dw;
			pq.push({ v[nxt],nxt });
		}
	}
	cout << v[N - 1];
	return 0;
}