#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M, S, E, incnter[10000], v1[10000], v2[10000], ans;
vector<vector<pair<int, int>>> adjv;
vector<vector<pair<int, int>>> radjv;

int main() {
	fastio;
	cin >> N >> M;
	adjv.resize(N);
	radjv.resize(N);
	rep(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c; a--; b--;
		adjv[a].push_back({ c,b });
		radjv[b].push_back({ c,a });
		incnter[b]++;
	}
	cin >> S >> E; S--; E--;
	queue<int> zq;
	rep(i, 0, N)
		if (incnter[i] == 0)
			zq.push(i);
	while (zq.size()) {
		int cur = zq.front(); zq.pop();
		rep(i, 0, adjv[cur].size()) {
			int w = adjv[cur][i].first;
			int nxt = adjv[cur][i].second;
			if (v1[nxt] < v1[cur] + w)
				v1[nxt] = v1[cur] + w;
			incnter[nxt]--;
			if (incnter[nxt] == 0)
				zq.push(nxt);
		}
	}
	queue<int> bq;
	bq.push(E);
	v2[E] = 1;
	while (bq.size()) {
		int cur = bq.front(); bq.pop();
		rep(i, 0, radjv[cur].size()) {
			int w = radjv[cur][i].first; // time
			int nxt = radjv[cur][i].second; // nxt
			if (!(v1[nxt] + w == v1[cur]))
				continue;
			ans++;
			if (!(v2[nxt] == 0))
				continue;
			v2[nxt] = 1;
			bq.push(nxt);
		}
	}
	printf("%d\n%d\n", v1[E], ans);
	return 0;
}