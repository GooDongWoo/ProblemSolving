#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int N, arr[100000];
LL dp[100000][2];

int main() {
	fastio;
	cin >> N;
	rep(i, 0, N) {
		cin >> arr[i];
	}

	dp[0][1] = arr[0];
	rep(i, 1, N) {
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i];
	}
	printf("%lld", min(dp[N - 1][0], dp[N - 1][1]));
	return 0;
}