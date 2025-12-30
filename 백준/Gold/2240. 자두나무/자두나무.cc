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

int T, W, dp[2][1001][31], counter[2] = { 1,0 };

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> T >> W;
	rep(i, 1, T + 1) {
		int val;
		cin >> val;
		dp[0][i][0] = dp[0][i - 1][0] + (val == 1);
		rep(j, 0, 2) {
			int offset = (j == val - 1) ? 1 : 0;
			rep(k, 1, W + 1) {
				dp[j][i][k] = max(dp[j][i - 1][k] + offset, dp[counter[j]][i - 1][k - 1] + offset);
			}
		}
	}
	int ans = 0;
	rep(i, 0, 2) {
		rep(j, 0, W + 1) {
			ans = max(ans, dp[i][T][j]);
		}
	}
	cout << ans;
	return 0;
}