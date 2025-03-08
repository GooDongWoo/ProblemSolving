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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

int N, M, v[1000], Q;
vector<vector<int>> adjv(1000);


int main(){
	fastio;
	cin >> N >> M;
	rep(i, 0, M) {
		int a, b;
		cin >> a >> b; a--; b--;
		adjv[a].push_back(b);
		adjv[b].push_back(a);
	}
	cin >> Q;
	rep(i, 0, Q) {
		int a, b;
		cin >> a >> b; a--; b--;
		adjv[a].push_back(b);
		adjv[b].push_back(a);
		memset(v, 0, sizeof(v));
		queue<int> q;
		v[0] = 1;
		q.push(0);
		while (q.size()) {
			int cur = q.front(); q.pop();
			rep(i, 0, adjv[cur].size()) {
				int nxt = adjv[cur][i];
				if (v[nxt]) continue;
				v[nxt] = v[cur] + 1;
				q.push(nxt);
			}
		}
		rep(i, 0, N)printf("%d ", v[i] - 1);
		printf("\n");
	}
	return 0;
}