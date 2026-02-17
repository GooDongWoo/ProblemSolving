#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <unordered_map>

#define rep(i, a, b) for (int i=a;i<b;++i)
using LL = long long;
using namespace std;

int N, M, K, cost[10000], ans;
bool v[10000];
vector<vector<int>> adjv;

int F(int idx) {
	int ret = 1e9;
	queue<int> q;
	v[idx] = 1;
	q.push(idx);
	while (q.size()) {
		int cur = q.front(); q.pop();
		ret = min(ret, cost[cur]);
		for (const int nxt : adjv[cur]) {
			if (v[nxt])continue;
			v[nxt] = 1;
			q.push(nxt);
		}
	}
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M >> K;
	adjv.resize(N);
	rep(i, 0, N) cin >> cost[i];
	rep(i, 0, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adjv[a].push_back(b);
		adjv[b].push_back(a);
	}

	rep(i, 0, N) {
		if (v[i]) continue;
		ans += F(i);
	}
	if (ans <= K) {
		cout << ans;
	}
	else {
		cout << "Oh no";
	}
	return 0;
}