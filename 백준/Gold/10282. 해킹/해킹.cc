#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;

int T, N, D, C, v[10000];
vector<vector<pair<int, int>>> adjv;

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cout.tie(NULL);
	cin >> T;
	rep(test_case, 0, T) {
		cin >> N >> D >> C; C--;
		// initialize
		adjv.clear();
		rep(i, 0, N) {
			v[i] = 1e9;
		}
		adjv.resize(N);

		//setting
		rep(i, 0, D) {
			int a, b, s;
			cin >> a >> b >> s;
			a--; b--;
			//adjv[a].push_back({ s,b });
			adjv[b].push_back({ s,a });
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
		pq.push({ 0,C });
		int ncnter = 0, tcnter = 0;
		while (pq.size()) {
			auto curp = pq.top(); pq.pop();
			int cw = curp.first, cur = curp.second;
			if (v[cur] <= cw) {
				continue;
			}
			v[cur] = cw;
			ncnter++;
			tcnter = max(tcnter, cw);
			for (const auto& nxtp : adjv[cur]) {
				int dw = nxtp.first, nxt = nxtp.second;
				if (v[nxt] <= cw + dw) {
					continue;
				}
				pq.push({ cw + dw,nxt });
			}
		}
		cout << ncnter << ' ' << tcnter << '\n';
	}
	return 0;
}