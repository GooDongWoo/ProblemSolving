#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

const LL MAX = 1e18;
int N, M, cnter[500];
vector<vector<pair<int, int>>> adjv;
LL cost[500];
bool inq[500];
queue<int> q;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> N >> M;
	adjv.resize(N);
	rep(i, 0, N) {
		cost[i] = MAX;
	}
	rep(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		adjv[a].push_back({ c,b });
	}
	rep(i, 0, N) {
		sort(adjv[i].begin(), adjv[i].end());
	}
	cost[0] = 0;
	q.push(0);
	inq[0] = true;
	while (q.size()) {
		int cur = q.front(); q.pop();
		inq[cur] = false;
		if (++cnter[cur] >= N) {
			cout << -1;
			return 0;
		}
		for (const auto& nxtp : adjv[cur]) {
			int nxt = nxtp.second;
			int w = nxtp.first;
			if (cost[cur] + w >= cost[nxt]) {
				continue;
			}
			cost[nxt] = cost[cur] + w;
			if (!inq[nxt]) {
				inq[nxt] = true;
				q.push(nxt);
			}
		}
	}
	rep(i, 1, N) {
		if (cost[i] >= MAX) {
			cout << -1 << '\n';
		}
		else {
			cout << cost[i] << '\n';
		}
	}
	return 0;
}