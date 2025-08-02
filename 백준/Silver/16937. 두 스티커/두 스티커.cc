#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int H, W, N, arr[100][2], ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> H >> W >> N;
	rep(i, 0, N) {
		cin >> arr[i][0] >> arr[i][1];
	}
	rep(i, 0, N) {
		vector<pair<int, int>> clist;
		if (H - arr[i][0] >= 0 && W - arr[i][1] >= 0) {
			clist.push_back({ H - arr[i][0], W - arr[i][1] });
		}
		if (W - arr[i][0] >= 0 && H - arr[i][1] >= 0) {
			clist.push_back({ H - arr[i][1], W - arr[i][0] });
		}
		if (clist.size() == 0) {
			continue;
		}
		rep(j, i + 1, N) {
			for (const auto& x : clist) {
				if ((arr[j][0] <= x.first && arr[j][1] <= W) || (arr[j][0] <= H && arr[j][1] <= x.second) ||
					(arr[j][1] <= x.first && arr[j][0] <= W) || (arr[j][1] <= H && arr[j][0] <= x.second)) {
					ans = max(ans, arr[i][0] * arr[i][1] + arr[j][0] * arr[j][1]);
				}
			}
		}
	}
	cout << ans;
	return 0;
}