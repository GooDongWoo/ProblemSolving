#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>

#define rep(i, a, b) for (int i=a;i<b;++i)
using LL = long long;
using namespace std;

int N, M, cnter[100];
vector<vector<int>> adjv[2];

int F(int idx, int opt) {
	int ret = 0;
	bool v[100];
	memset(v, 0, sizeof(v));
	queue<int> q;

	v[idx] = 1;
	q.push(idx);
	while (q.size()) {
		int cur = q.front();
		q.pop();
		ret++;
		for (const int nxt : adjv[opt][cur]) {
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

	cin >> N >> M;
	adjv[0].resize(N);
	adjv[1].resize(N);

	rep(i, 0, M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adjv[0][a].push_back(b);
		adjv[1][b].push_back(a);
	}
	rep(i, 0, N) {
		int tmp = 0;
		rep(j, 0, 2) {
			tmp += F(i, j);
		}
		tmp--;
		cnter[i] = N - tmp;
	}
	rep(i, 0, N) {
		cout << cnter[i] << '\n';
	}
	return 0;
}