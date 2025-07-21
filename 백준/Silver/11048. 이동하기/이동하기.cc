#define rep(i,a,b) for(int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>

using namespace std;

int R, C, arr[1001][1001], dp[1001][1001];

int main() {
	cin >> R >> C;
	rep(i, 1, R + 1) {
		rep(j, 1, C + 1) {
			cin >> arr[i][j];
		}
	}
	rep(i, 1, R + 1) {
		rep(j, 1, C + 1) {
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j]);
		}
	}
	cout << dp[R][C];
}