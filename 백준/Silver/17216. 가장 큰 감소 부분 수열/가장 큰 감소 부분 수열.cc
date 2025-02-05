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

int n, arr[1000], dp[1000];

int main() {
	fastio;
	cin >> n;
	rep(i, 0, n) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	dp[0] = arr[0];
	rep(i, 1, n) rep(j, 0, i) if (arr[i] < arr[j]) dp[i] = max(dp[i], dp[j] + arr[i]);
	int ans;
	ans = *max_element(dp,dp+n);
	printf("%d", ans);
	
	return 0;
}
