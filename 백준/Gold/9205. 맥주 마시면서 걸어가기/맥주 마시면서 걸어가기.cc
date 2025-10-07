#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int T, N, v[102];
pair<int, int> mid[102];

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> T;
	rep(test_case, 0, T) {
		memset(v, 0, sizeof(v));
		cin >> N;
		rep(i, 0, N + 2) {
			cin >> mid[i].first >> mid[i].second;
		}
		queue<pair<int, int>> q;
		q.push({ mid[0].first,mid[0].second });
		while (q.size()) {
			auto curp = q.front(); q.pop();
			int cy = curp.first, cx = curp.second;
			rep(i, 1, N + 2) {
				int ny = mid[i].first, nx = mid[i].second;
				int dy = abs(ny - cy), dx = abs(nx - cx);
				if (v[i] || (dy + dx > 1000)) {
					continue;
				}
				v[i] = 1;
				q.push({ ny,nx });
			}
		}
		cout << (v[N + 1] ? "happy\n" : "sad\n");
	}
	return 0;
}
