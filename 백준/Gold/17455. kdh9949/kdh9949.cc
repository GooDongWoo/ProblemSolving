#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

int n, m;
string nodeChars;
vector<vector<int>> adjList;
vector<int> inDegree;
vector<int> dp;
map<char, char> nextChar;
set<int> s1;

void solve() {
	cin.tie(0)->sync_with_stdio(false);

	cin >> n >> m;
	cin >> nodeChars;
	nodeChars = " " + nodeChars;

	adjList.assign(n + 1, vector<int>());
	inDegree.assign(n + 1, 0);
	dp.assign(n + 1, 0);

	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		if (nextChar[nodeChars[u]] == nodeChars[v]) {
			adjList[u].push_back(v);
			inDegree[v]++;
			s1.insert(u);
			s1.insert(v);
		}
		if (nextChar[nodeChars[v]] == nodeChars[u]) {
			adjList[v].push_back(u);
			inDegree[u]++;
			s1.insert(u);
			s1.insert(v);
		}
	}
	queue<int> q;
	rep(i, 1, n + 1) {
		if (s1.count(i) && inDegree[i] == 0) {
			q.push(i);
			if (nodeChars[i] == 'K') {
				dp[i] = 1;
			}
			else if (nodeChars[i] == 'D') {
				dp[i] = -1;
			}
			else {
				dp[i] = 0;
			}
		}
	}

	int pc = 0;
	int ans = 0;
	while (q.size()) {
		int u = q.front(); q.pop();
		pc++;
		for (const int& v : adjList[u]) {
			dp[v] = max(dp[v], dp[u] + 1);
			ans = max(dp[v], ans);
			inDegree[v]--;
			if (inDegree[v] == 0) {
				q.push(v);
			}
		}
	}
	int finalLen = (ans / 3) * 3;
	if (s1.size() != pc || finalLen <= 0) {
		cout << -1;
	}
	else {
		cout << finalLen;
	}
}

int main() {
	nextChar['K'] = 'D';
	nextChar['D'] = 'H';
	nextChar['H'] = 'K';
	solve();
	return 0;
}