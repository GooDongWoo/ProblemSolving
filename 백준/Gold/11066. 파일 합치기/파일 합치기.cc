#include <iostream>
#include <algorithm>
#include <cstring>
#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;
using namespace std;
int T, K, dp[500][500], opt[500][500], arr[500], psum[500];

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> T;
	rep(test_case, 1, T + 1) {
		cin >> K;
		rep(i, 0, K) {
			dp[i][i] = 0;
			opt[i][i] = i;
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
				int j = i + dist;
				int cost = (i == 0) ? psum[j] : psum[j] - psum[i - 1];
				
				int left = opt[i][j - 1];
				int right = (i + 1 <= j) ? opt[i + 1][j] : j;
				
				rep(k, left, right + 1) {
					int val = dp[i][k] + dp[k + 1][j] + cost;
					if (val < dp[i][j]) {
						dp[i][j] = val;
						opt[i][j] = k;
					}
				}
			}
		}
		cout << dp[0][K - 1] << '\n';
	}
	return 0;
}