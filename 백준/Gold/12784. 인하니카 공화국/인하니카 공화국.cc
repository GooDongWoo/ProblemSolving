#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define LL long long

using namespace std;

int T, N, M;
bool v[1000];
vector<vector<pair<int, int>>> adjv;

int dfs(int num) {
	v[num] = true;
	int cur = 0, bef;
	rep(i, 0, adjv[num].size()) {
		auto nxtp = adjv[num][i];
		int nw = nxtp.first, nxt = nxtp.second;
		if (v[nxt]) continue;
		bef = dfs(nxt);
		cur += min(bef, nw);
	}
	if (cur == 0)
		return 1e9;
	else
		return cur;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	rep(test_case, 1, T + 1) {
		cin >> N >> M;
		adjv.clear();
		adjv.resize(N);
		memset(v, 0, sizeof(v));
		rep(i, 0, M) {
			int a, b, c;
			cin >> a >> b >> c; a--; b--;
			adjv[a].push_back({ c,b });
			adjv[b].push_back({ c,a });
		}
		if (N == 1) {
			printf("%d\n",0);
			continue;
		}
		printf("%d\n", dfs(0));
	}
	return 0;
}