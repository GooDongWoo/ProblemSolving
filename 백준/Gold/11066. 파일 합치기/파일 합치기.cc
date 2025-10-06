#include <iostream>
#include <algorithm>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int T, K, dp[500][500], arr[500], psum[500];

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> T;
	rep(test_case, 1, T + 1) {
		cin >> K;
		rep(i, 0, K) {
			dp[i][i] = 0;
			rep(j, i + 1, K) {
				dp[i][j] = 1e9;
			}
		}
		rep(i, 0, K) {
			cin >> arr[i];
		}
		psum[0] = arr[0];
		rep(i, 1, K) {
			psum[i] = arr[i] + psum[i - 1];
		}
		rep(dist, 1, K) {
			rep(i, 0, K - dist) {
				rep(sep, i, i + dist) {
					if (i == 0) {
						dp[i][i + dist] = min(dp[i][i + dist], dp[i][sep] + dp[sep + 1][i + dist] + psum[i + dist]);
					}
					else {
						dp[i][i + dist] = min(dp[i][i + dist], dp[i][sep] + dp[sep + 1][i + dist] + psum[i + dist] - psum[i - 1]);
					}
				}
			}
		}
		cout << dp[0][K - 1] << '\n';
	}

	return 0;
}