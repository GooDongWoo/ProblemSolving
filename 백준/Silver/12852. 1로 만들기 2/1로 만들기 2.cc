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
#include <unordered_map>
#include <set>
#include <cmath>
#include <cstring>

using namespace std;

#define LIMIT 1000000
int N, dp[LIMIT + 1];

int main() {
	fastio;
	cin >> N;
	rep(i, 0, LIMIT + 1)
		dp[i] = 1e9;
	dp[0] = 0;
	dp[1] = 0;
	rep(i, 2, LIMIT + 1) {
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i - 1 > 0)
			dp[i] = min(dp[i], dp[i - 1] + 1);
	}
	printf("%d\n", dp[N]);
	int start = N;
	while (start != 1) {
		printf("%d ", start);
		if (start % 3 == 0 && dp[start] == dp[start / 3] + 1)
			start /= 3;
		else if (start % 2 == 0 && dp[start] == dp[start / 2] + 1)
			start /= 2;
		else
			start -= 1;
	}
	printf("1\n");
}