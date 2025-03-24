#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cstring>

using namespace std;

int N, dists[3000], lpart, bef[3000];
vector<vector<int>> adjv(3000);
bool v[3000],Flag;

void dfs(int num) {
	rep(i, 0, adjv[num].size()) {
		int nxt = adjv[num][i];
		if (nxt == bef[num]) continue;
		if (v[nxt] == 0) {
			v[nxt] = 1;
			bef[nxt] = num;
			dfs(nxt);
		}
		else {
			if (Flag) return;
			lpart = nxt;
			int cn = num;
			while (cn != nxt) {
				dists[cn] = 0;
				cn = bef[cn];
			}
			dists[cn] = 0;
			Flag = 1;
		}
	}
}
int main() {
	fastio;
	cin >> N;
	rep(i, 0, N) {
		int a, b;
		cin >> a >> b; a--; b--;
		adjv[a].push_back(b);
		adjv[b].push_back(a);
	}
	memset(dists, -1, sizeof(dists));
	v[0] = 1;
	dfs(0);

	memset(v, 0, sizeof(v));
	queue<int> q;
	q.push(lpart);
	v[lpart] = 1;
	while (q.size()) {
		int cur = q.front(); q.pop();
		rep(i, 0, adjv[cur].size()) {
			int nxt = adjv[cur][i];
			if (v[nxt]) continue;
			v[nxt] = 1;
			q.push(nxt);
			if (dists[nxt] != 0)
				dists[nxt] = dists[cur] + 1;
		}
	}
	rep(i, 0, N)printf("%d ", dists[i]);
}