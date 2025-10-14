#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, cost[500], incnter[500], starttime[500];
vector<vector<int>> adjv;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	adjv.resize(N);
	queue<pair<int, int>> q;
	rep(i, 0, N) {
		cin >> cost[i];
		int num = 0;
		cin >> num;
		while (num != -1) {
			adjv[--num].push_back(i);
			incnter[i]++;
			cin >> num;
		}
		if (incnter[i] == 0) {
			q.push({ starttime[i] + cost[i],i });
		}
	}
	while (q.size()) {
		auto curp = q.front(); q.pop();
		int ct = curp.first, cur = curp.second;
		for (const int nxt : adjv[cur]) {
			starttime[nxt] = max(starttime[nxt], ct);
			incnter[nxt]--;
			if (incnter[nxt] == 0) {
				q.push({ starttime[nxt] + cost[nxt] ,nxt });
			}
		}
	}
	rep(i, 0, N) {
		cout << starttime[i] + cost[i] << '\n';
	}

	return 0;
}