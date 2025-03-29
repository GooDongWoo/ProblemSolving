#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#include <iostream>

using namespace std;

int N, K, dp[10001], arr[100];

int main() {
	fastio;
	cin >> N >> K;
	rep(i, 0, N)
		cin >> arr[i];
	rep(i, 0, K + 1)
		dp[i] = 1e9;
	rep(i, 0, N) {
		if (arr[i] > 10000) continue;
		dp[arr[i]] = 1;
		rep(j, arr[i] + 1, K + 1) {
			if (dp[j - arr[i]] != 1e9)
				dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}
	if (dp[K] == 1e9)
		printf("-1");
	else
		printf("%d\n", dp[K]);
	return 0;
}