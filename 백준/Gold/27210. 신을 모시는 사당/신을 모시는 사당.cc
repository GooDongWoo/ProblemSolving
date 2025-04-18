#include <iostream>

#define rep(i,a,b) for(int i=a;i<b;++i)
using namespace std;

int N, arr[100000], dp[100000][2], ans = 1;

int main() {
	cin >> N;
	rep(i, 0, N)
		cin >> arr[i];

	if (arr[0] == 1)
		dp[0][0] = 1;
	else
		dp[0][1] = 1;

	rep(i, 1, N) {
		if (arr[i] == 1) {
			dp[i][0] = dp[i - 1][0] + 1;
			dp[i][1] = max(dp[i - 1][1] - 1, 0);
		}
		else {
			dp[i][0] = max(dp[i - 1][0] - 1, 0);
			dp[i][1] = dp[i - 1][1] + 1;
		}
		ans = max(max(ans, dp[i][0]), dp[i][1]);
	}
	printf("%d\n", ans);
	return 0;
}