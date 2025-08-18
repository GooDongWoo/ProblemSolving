#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

#define MAX 2e18

int N, S, E, M, earn[50];
vector<vector<pair<int, int>>> adjv;
LL dist[50];
vector<int> negativeCycle;
bool v[50];
queue<int> q;
set<int> s1;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> S >> E >> M;
	adjv.resize(N);
	rep(i, 0, M) {
		int s, e, w;
		cin >> s >> e >> w;
		adjv[s].push_back({ e,w });
	}
	rep(i, 0, N) {
		cin >> earn[i];
	}

	rep(i, 0, N) {
		dist[i] = MAX;
	}
	dist[S] = -earn[S];

	rep(step, 0, N - 1) {
		rep(cur, 0, N) {
			if (dist[cur] >= MAX) {
				continue;
			}
			for (const auto& x : adjv[cur]) {
				int nxt = x.first, w = x.second;
				if (dist[nxt] > dist[cur] + w - earn[nxt]) {
					dist[nxt] = dist[cur] + w - earn[nxt];
				}
			}
		}
	}
	if (dist[E] >= MAX) {
		cout << "gg\n";
		return 0;
	}
	rep(cur, 0, N) {
		if (dist[cur] >= MAX) {
			continue;
		}
		for (const auto& x : adjv[cur]) {
			int nxt = x.first, w = x.second;
			if (dist[nxt] > dist[cur] + w - earn[nxt]) {
				s1.insert(cur);
			}
		}
	}
	for (const auto& x : s1) {
		q.push(x);
		v[x] = 1;
	}
	while (q.size()) {
		int cur = q.front(); q.pop();
		for (const auto& x : adjv[cur]) {
			int nxt = x.first;
			if (v[nxt]) {
				continue;
			}
			v[nxt] = 1;
			q.push(nxt);
		}
	}
	if (v[E]) {
		cout << "Gee\n";
	}
	else {
		cout << -dist[E] << '\n';
	}
	return 0;
}