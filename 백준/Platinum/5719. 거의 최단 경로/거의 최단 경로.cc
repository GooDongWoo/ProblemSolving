#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

struct Item {
	int w, end;
	bool operator>(const Item& o) const {
		return(w > o.w);
	}
};
int N, M, S, E, dists[500];
bool v[500], destroyed[500][500];
vector<vector<pair<int, int>>> adjv(500);
vector<vector<pair<int, int>>> radjv(500);

void dijk() {
	priority_queue<Item, vector<Item>, greater<>> pq;
	pq.push({ 0,S });
	while (pq.size()) {
		auto curp = pq.top(); pq.pop();
		int w = curp.w, end = curp.end;
		if (v[end]) continue;
		v[end] = 1;
		dists[end] = w;
		for (const auto& nxtp : adjv[end]) {
			int nxt = nxtp.se, nw = nxtp.fi;
			if (v[nxt] || destroyed[end][nxt])continue;
			pq.push({ w + nw,nxt });
		}
	}
}

int main() {
	fastio;
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		cin >> S >> E;
		rep(i, 0, N) {
			adjv[i].clear();
			radjv[i].clear();
		}
		rep(i, 0, M) {
			int a, b, c;
			cin >> a >> b >> c;
			adjv[a].push_back({ c,b });
			radjv[b].push_back({ c,a });
		}
		memset(v, 0, sizeof(v));
		memset(dists, 0, sizeof(dists));
		memset(destroyed, 0, sizeof(destroyed));
		dijk();
		memset(v, 0, sizeof(v));
		// E에서부터 BFS(역방향 간선만)돌리고 돌린 곳의 최단거리가 딱 차이면 그 간선을 plist에 추가
		// 그리고 그 bef 노드를 큐에 추가
		queue<int> q;
		q.push(E);
		v[E] = 1;
		while (q.size()) {
			int cur = q.front(); q.pop();
			rep(i, 0, radjv[cur].size()) {
				int bef = radjv[cur][i].se;
				int w = radjv[cur][i].fi;
				if (dists[bef] + w == dists[cur]) {// 간선 체크
					destroyed[bef][cur] = 1;
					if (v[bef] == 0) {
						v[bef] = 1;
						q.push(bef);
					}
				}
			}
		}
		//간선 전부 제거-> destroyed로 대체

		//다시 다익스트라
		memset(v, 0, sizeof(v));
		memset(dists, 0, sizeof(dists));
		dijk();
		if (dists[E]) printf("%d\n", dists[E]);
		else printf("-1\n");
	}
}