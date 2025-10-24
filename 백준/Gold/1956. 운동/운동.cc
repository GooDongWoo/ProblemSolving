#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

const int MAX = 1e9;
int V, E, ans = MAX;
int dists[400][400];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> V >> E;
	rep(i, 0, V) {
		rep(j, 0, V) {
			dists[i][j] = MAX;
		}
	}
	rep(i, 0, E) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		dists[a][b] = c;
	}
	rep(i, 0, V) {
		rep(j, 0, V) {
			rep(k, 0, V) {
				dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
			}
		}
	}
	rep(i, 0, V - 1) {
		rep(j, i + 1, V) {
			if (dists[i][j] + dists[j][i] >= MAX) {
				continue;
			}
			ans = min(ans, dists[i][j] + dists[j][i]);
		}
	}
	cout << ((ans >= MAX) ? -1 : ans);

	return 0;
}