#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, K, q1, q2, Rank[100000], min1, max1;
vector<vector<pair<int, int>>> Adjv;
int nDP[20][100000], minDP[20][100000], maxDP[20][100000];
bool v[100000];

int LCA(int a, int b) {
	if (Rank[a] != Rank[b]) {
		if (Rank[a] > Rank[b]) {
			swap(a, b);
		}
		int diff = Rank[b] - Rank[a];
		while (diff > 0) {
			int logVal = 19;
			while ((1 << logVal) > diff) {
				logVal--;
			}
			min1 = min(min1, minDP[logVal][b]);
			max1 = max(max1, maxDP[logVal][b]);
			b = nDP[logVal][b];
			diff -= (1 << logVal);
		}
	}
	while (a != b) {
		int logVal = 0;
		while (nDP[logVal][a] != nDP[logVal][b]) {
			logVal++;
		}
		if (logVal != 0) {
			min1 = min(min1, minDP[logVal - 1][a]);
			max1 = max(max1, maxDP[logVal - 1][a]);
			min1 = min(min1, minDP[logVal - 1][b]);
			max1 = max(max1, maxDP[logVal - 1][b]);

			a = nDP[logVal - 1][a];
			b = nDP[logVal - 1][b];
		}
		else {
			min1 = min(min1, minDP[logVal][a]);
			max1 = max(max1, maxDP[logVal][a]);
			min1 = min(min1, minDP[logVal][b]);
			max1 = max(max1, maxDP[logVal][b]);

			a = nDP[logVal][a];
			b = nDP[logVal][b];
		}
	}
	return a;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	Adjv.resize(N);
	rep(i, 0, N - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		Adjv[a].push_back({ b,c });
		Adjv[b].push_back({ a,c });
	}
	// bfs로 트리 생성
	queue<int> q;
	Rank[0] = 0;
	v[0] = 1;
	q.push(0);
	while (q.size()) {
		int cur = q.front(); q.pop();
		for (const auto& nxtp : Adjv[cur]) {
			int nxt = nxtp.first;
			int w = nxtp.second;
			if (v[nxt]) {
				continue;
			}
			v[nxt] = 1;
			Rank[nxt] = Rank[cur] + 1;
			nDP[0][nxt] = cur;
			minDP[0][nxt] = w;
			maxDP[0][nxt] = w;
			q.push(nxt);
		}
	}
	//트리로 희소맵
	//1. 해당 노드
	//2. 해당 노드까지 중에서 최소 거리
	//3. 해당 노드까지 중에서 최대 거리
	rep(steps, 0, 20) {
		minDP[steps][0] = 1e9;
		maxDP[steps][0] = -1e9;
	}
	rep(steps, 1, 20) {
		rep(Node, 1, N) {
			nDP[steps][Node] = nDP[steps - 1][nDP[steps - 1][Node]];
			minDP[steps][Node] = min(minDP[steps - 1][Node], minDP[steps - 1][nDP[steps - 1][Node]]);
			maxDP[steps][Node] = max(maxDP[steps - 1][Node], maxDP[steps - 1][nDP[steps - 1][Node]]);
		}
	}

	//쿼리 입력받고 로그로 끝내면서 쿼리 처리
	cin >> K;
	rep(i, 0, K) {
		min1 = 1e9;
		max1 = -1e9;
		cin >> q1 >> q2;
		q1--; q2--;
		int lca = LCA(q1, q2);
		cout << min1 << ' ' << max1 << '\n';
	}
	return 0;
}