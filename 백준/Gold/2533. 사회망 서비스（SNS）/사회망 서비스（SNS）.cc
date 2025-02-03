#define _CRT_SECURE_NO_WARNINGS
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
#include <map>
#include <set>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX 1000000
int n, a, b, v[MAX], dp[MAX][2];
vector<vector<int>> adj(MAX);
void DFS(int nn) {
	v[nn] = 1;
	rep(i, 0, adj[nn].size()) {
		if (v[adj[nn][i]]) continue;
		DFS(adj[nn][i]);
	}
	rep(i, 0, adj[nn].size()) dp[nn][1] += min(dp[adj[nn][i]][0], dp[adj[nn][i]][1]);
	dp[nn][1]++;
	rep(i, 0, adj[nn].size()) {
		dp[nn][0] += dp[adj[nn][i]][1];
	}
}

int main() {
	fastio;
	cin >> n;
	vector <pair<int, int>> acnter;
	rep(i, 0, n - 1) {
		cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	DFS(0);
	printf("%d\n", min(dp[0][0], dp[0][1]));
	return 0;
}