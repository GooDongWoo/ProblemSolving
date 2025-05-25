#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
bool mat[301][301];
LL ans, dp[301][301];

int main() {
	fastio;
	cin >> N >> M;
	rep(i, 0, N) {
		int a, b;
		cin >> a >> b;
		mat[b][a] = 1;
	}

	rep(i, 1, 301) {
		dp[i][0] = dp[i - 1][0];
		if (mat[i][0])
			dp[i][0] += max(0, M - i);

		dp[0][i] = dp[0][i - 1];
		if (mat[0][i])
			dp[0][i] += max(0, M - i);
	}

	rep(j, 1, 301) {
		rep(i, 1, 301) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (mat[i][j])
				dp[i][j] += max(0, M - i - j);
		}
	}

	printf("%lld\n", dp[300][300]);
	return 0;
}