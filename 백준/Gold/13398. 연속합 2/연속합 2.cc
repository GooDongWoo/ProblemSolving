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
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

int N, arr[100000], dp[100000][2];


int main() {
	fastio;
	cin >> N;
	rep(i, 0, N)cin >> arr[i];

	dp[0][0] = arr[0];
	dp[0][1] = 0;
	rep(i, 1, N) {
		dp[i][0] = max(dp[i - 1][0], 0) + arr[i];
		dp[i][1] = max(dp[i - 1][0] + 0, dp[i - 1][1] + arr[i]);
	}
	int max1 = -1e9;
	rep(i, 0, N) {
		int tmp = dp[i][1] > 0 ? dp[i][1] : -1e9;
		max1 = max(max1, max(dp[i][0], tmp));

	}
	printf("%d\n", max1);
	return 0;
}