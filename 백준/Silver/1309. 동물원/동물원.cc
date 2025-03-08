#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

int N, dp[100000][3];
const int MOD = 9901;
int main(){
	fastio;
	cin >> N;
	dp[0][0] = 1; dp[0][1] = 1; dp[0][2] = 1;
	rep(i, 1, N) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
	}
	int ans = dp[N - 1][0] + dp[N - 1][1] + dp[N - 1][2];
	printf("%d\n", ans% MOD);
	return 0;
}