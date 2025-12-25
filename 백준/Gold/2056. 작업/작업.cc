#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, inCnt[10000], times[10000], v[10000],ans;
vector<vector<int>> adjv;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	adjv.resize(N);
	queue<int> q;
	rep(i, 0, N) {
		cin >> times[i] >> inCnt[i];
		rep(j, 0, inCnt[i]) {
			int tmp;
			cin >> tmp;
			adjv[tmp - 1].push_back(i);
		}
		if (inCnt[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		int cur = q.front(); q.pop();
		ans = max(ans, v[cur]+times[cur]);
		for (const auto& nxt : adjv[cur]) {
			inCnt[nxt]--;
			v[nxt] = max(v[nxt], v[cur] + times[cur]);
			if (inCnt[nxt] <= 0) {
				q.push(nxt);
			}
		}
	}
	cout << ans;
	return 0;
}