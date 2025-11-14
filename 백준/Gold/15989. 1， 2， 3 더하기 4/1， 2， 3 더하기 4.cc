#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int T, N, dp[10001][3];

void run() {
	dp[1][0] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;
	dp[3][0] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	rep(i, 4, 10001) {
		dp[i][0] = dp[i - 1][0];
		dp[i][1] = dp[i - 2][0] + dp[i - 2][1];
		dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2];
	}
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	run();
	cin >> T;
	rep(test_case, 0, T) {
		cin >> N;
		cout << dp[N][0] + dp[N][1] + dp[N][2] << '\n';
	}
	return 0;
}