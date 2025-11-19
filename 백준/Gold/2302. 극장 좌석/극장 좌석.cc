#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, M, dp[40][3];
bool dat[41];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N >> M;
	rep(i, 0, M) {
		int a;
		cin >> a;
		dat[a - 1] = true;
	}
	dp[0][0] = 0;
	dp[0][1] = 1;
	if (!dat[0]) {
		dp[0][2] = 1;
	}
	rep(i, 1, N) {
		if (!dat[i]) {
			dp[i][0] = dp[i - 1][2];
			dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
			dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
		}
		else {
			dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
		}
	}
	cout << dp[N - 1][0] + dp[N - 1][1];
	return 0;
}