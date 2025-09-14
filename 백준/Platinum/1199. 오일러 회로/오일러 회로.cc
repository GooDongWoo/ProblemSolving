#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <cstring>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int N, adjm[1000][1000], iocnter[1000];
bool Flag = 1;
vector<queue<int>> adjv;

void dfs(int cur) {
	while(adjv[cur].size()){
		int nxt = adjv[cur].front(); adjv[cur].pop();
		if (nxt == cur || adjm[cur][nxt] == 0) {
			continue;
		}
		adjm[cur][nxt]--;
		adjm[nxt][cur]--;
		dfs(nxt);
	}
	cout << cur + 1 << ' ';
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	adjv.resize(N);
	rep(i, 0, N) {
		rep(j, 0, N) {
			cin >> adjm[i][j];
			iocnter[i] += adjm[i][j];
			rep(k, 0, adjm[i][j]) {
				adjv[i].push(j);
			}
		}
		if (iocnter[i] & 1) {
			Flag = 0;
		}
	}
	if (!Flag) {
		cout << -1;
		return 0;
	}
	dfs(0);
	return 0;
}