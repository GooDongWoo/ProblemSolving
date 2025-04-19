#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, L;
LL ans, dp[2], tmp[2];
int main() {
	fastio;
	cin >> N >> M;
	vector<vector<pair<int, int>>> arr(N);
	rep(i, 0, M) {
		cin >> L;
		rep(j, 0, L) {
			int p, v;
			cin >> p >> v; p--;
			arr[p].push_back({ i,v });
		}
	}
	rep(i, 0, N) {
		int asize = arr[i].size();
		if (asize == 0)
			continue;
		dp[0] = arr[i][0].second;
		dp[1] = 0;
		rep(j, 1, asize) {
			if (arr[i][j].first == arr[i][j - 1].first + 1) {
				tmp[0] = dp[1] + arr[i][j].second;
				tmp[1] = max(dp[0], dp[1]);
				dp[0] = tmp[0];
				dp[1] = tmp[1];
			}
			else if (j + 1 < asize && arr[i][j].first == arr[i][j + 1].first - 1) {
				tmp[0] = max(dp[0], dp[1]) + arr[i][j].second;
				tmp[1] = max(dp[0], dp[1]);
				dp[0] = tmp[0];
				dp[1] = tmp[1];
			}
			else {
				dp[0] += arr[i][j].second;
				dp[1] += arr[i][j].second;
			}
		}
		ans += max(dp[0], dp[1]);
	}
	printf("%lld\n", ans);
	return 0;
}