#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

#define MAX 1e18

int N, O, S, E, M, P, Q;
vector<vector<int>> adjv;
vector<vector<pair<int, LL>>> elevator;
LL horizontals;
LL dist[5000][5000];
bool v[5000];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> O >> S >> E;
	S--; E--;
	adjv.resize(N);
	rep(i, 0, N) {
		rep(j, 0, N) {
			dist[i][j] = MAX;
		}
	}
	cin >> M;
	rep(i, 0, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adjv[a].push_back(b);
		adjv[b].push_back(a);
	}
	rep(start, 0, N) {
		memset(v, 0, sizeof(v));
		v[start] = 1;
		dist[start][start] = 0;
		queue<int> q;
		q.push(start);
		while (q.size()) {
			int cur = q.front(); q.pop();
			for (const int& nxt : adjv[cur]) {
				if (v[nxt]) {
					continue;
				}
				v[nxt] = 1;
				dist[start][nxt] = dist[start][cur] + 1;
				q.push(nxt);
			}
		}
	}
	cin >> P;
	elevator.resize(O);
	rep(i, 0, P) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		elevator[a].push_back({ b ,MAX });
	}

	rep(j, 0, elevator[0].size()) {
		elevator[0][j].second = dist[S][elevator[0][j].first];
	}
	rep(i, 1, O) {
		rep(j, 0, elevator[i].size()) {
			rep(k, 0, elevator[i - 1].size()) {
				elevator[i][j].second = min(elevator[i][j].second, elevator[i - 1][k].second + dist[elevator[i - 1][k].first][elevator[i][j].first]);
			}
		}
	}
	horizontals = 1e18;
	if (O == 1) {
		horizontals = dist[S][E];
	}
	else {
		rep(i, 0, elevator[O - 2].size()) {
			if (elevator[O - 2][i].second < 1e18 || dist[elevator[O - 2][i].first][E] < 1e18) {
				horizontals = min(horizontals, elevator[O - 2][i].second + dist[elevator[O - 2][i].first][E]);
			}
		}
	}

	cin >> Q;
	rep(i, 0, Q) {
		LL a, b;
		cin >> a >> b;
		if (horizontals >= 1e18) {
			cout << -1 << '\n';
		}
		else {
			cout << ((horizontals * a) + ((O - 1) * b)) << '\n';
		}
	}

	return 0;
}