#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
using namespace std;

int N, K, arr[500], dp[501][500], ans = 1;

int main() {
	fastio;
	cin >> N >> K;
	rep(i, 0, N) {
		cin >> arr[i];
		dp[0][i] = 1;
	}
	rep(i, 1, N) {
		rep(j, 0, K + 1) {
			rep(a, 0, i) {
				if (arr[i] >= arr[a]) {
					if (dp[j][a] == 0) {
						continue;
					}
					dp[j][i] = max(dp[j][i], dp[j][a] + 1);
				}
				else {
					if (j != 0) {
						dp[j][i] = max(dp[j][i], dp[j - 1][a] + 1);
					}
				}
				ans = max(ans, dp[j][i]);
			}
		}
	}
	printf("%d\n", ans);
}