#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;

int T, N, D, C, v[10000];
vector<pair<int, int>> adjv[10000];

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cout.tie(NULL);
	cin >> T;
	rep(test_case, 0, T) {
		cin >> N >> D >> C; C--;
		// initialize
		rep(i, 0, N) {
			adjv[i].clear();
			v[i] = 1e9;
		}

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
		v[C] = 0;
		while (pq.size()) {
			auto curp = pq.top(); pq.pop();
			int cw = curp.first, cur = curp.second;
			if (v[cur] < cw) {
				continue;
			}
			for (const auto& nxtp : adjv[cur]) {
				int dw = nxtp.first, nxt = nxtp.second;
				if (v[nxt] <= cw + dw) {
					continue;
				}
				v[nxt] = cw + dw;
				pq.push({ cw + dw,nxt });
			}
		}
		int cnt = 0;
		int max_time = 0;
		rep(i, 0, N) {
			if (v[i] != 1e9) {
				cnt++;
				if (v[i] > max_time) {
					max_time = v[i];
				}
			}
		}
		cout << cnt << ' ' << max_time << '\n';
	}
	return 0;
}