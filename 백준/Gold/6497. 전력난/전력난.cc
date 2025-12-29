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

int N, M;
bool v[200000];
vector<vector<pair<int, int>>> adjv;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		adjv.clear();
		adjv.resize(N);
		memset(v, 0, sizeof(v));
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
		int tot = 0, minSpan = 0;

		rep(i, 0, M) {
			int x, y, z;
			cin >> x >> y >> z;
			adjv[x].push_back({ z,y });
			adjv[y].push_back({ z,x });
			tot += z;
		}
		pq.push({ 0,0 });
		while (pq.size()) {
			auto curp = pq.top(); pq.pop();
			int cw = curp.first, cur = curp.second;
			if (v[cur])continue;
			v[cur] = 1;
			minSpan += cw;
			for (const pair<int, int>& nxtp : adjv[cur]) {
				int nxtw = nxtp.first, nxt = nxtp.second;
				if (v[nxt])continue;
				pq.push({nxtw,nxt});
			}
		}
		cout << tot-minSpan << '\n';
	}
	return 0;
}