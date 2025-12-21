#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, v[50];
vector<vector<int>> adjv;
pair<int, int> ans[50];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	adjv.resize(N);
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		a--; b--;
		adjv[a].push_back(b);
		adjv[b].push_back(a);
	}
	rep(i, 0, N) {
		memset(v, 0, sizeof(v));
		queue<int> q;
		q.push(i);
		v[i] = 1;
		int dist = 0;
		while (q.size()) {
			int cur = q.front(); q.pop();
			for (const auto& nxt : adjv[cur]) {
				if (v[nxt]) {
					continue;
				}
				v[nxt] = v[cur] + 1;
				q.push(nxt);
			}
		}
		int mini = 0;
		rep(j, 0, N) {
			mini = max(mini, v[j] - 1);
		}
		ans[i] = { mini,i + 1 };
	}
	sort(ans, ans + N);
	int bestScore = ans[0].first;
	int cnt = N;
	rep(i, 1, N) {
		if (ans[i].first != bestScore) {
			cnt = i;
			break;
		}
	}
	cout << bestScore << ' ' << cnt << '\n';
	rep(i, 0, cnt) {
		cout << ans[i].second << ' ';
	}
	return 0;
}