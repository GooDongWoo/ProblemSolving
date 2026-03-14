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

int N, M, inCnt[1000], ans[1000];
vector<vector<int>> adjv;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M;
	adjv.resize(N);

	rep(i, 0, M) {
		int a, b;
		cin >> a >> b; a--; b--;
		adjv[a].push_back(b);
		inCnt[b]++;
	}
	queue<int> q;
	rep(i, 0, N) {
		if (inCnt[i] == 0) {
			q.push(i);
		}
	}
	int time = 0;
	while (q.size()) {
		int miniCycle = q.size();
		time++;
		rep(i, 0, miniCycle) {
			int cur = q.front(); q.pop();
			ans[cur] = time;
			for (const int& nxt : adjv[cur]) {
				inCnt[nxt]--;
				if (inCnt[nxt] == 0) {
					q.push(nxt);
				}
			}
		}
	}
	rep(i, 0, N) {
		cout << ans[i] << ' ';
	}

	return 0;
}