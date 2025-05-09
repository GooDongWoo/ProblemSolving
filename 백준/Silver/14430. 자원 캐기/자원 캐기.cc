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

int N, M, arr[301][301], dp[301][301];

int main() {
	fastio;
	cin >> N >> M;
	rep(i, 1, N + 1)
		rep(j, 1, M + 1)
		cin >> arr[i][j];
	rep(i, 1, N + 1)
		rep(j, 1, M + 1) {
		dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
	}
	printf("%d\n", dp[N][M]);
}