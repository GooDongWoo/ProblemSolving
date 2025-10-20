#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int T, N, arr[20], dp[10001], target;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> T;
	rep(test_case, 0, T) {
		memset(dp, 0, sizeof(dp));
		cin >> N;
		rep(i, 0, N) {
			cin >> arr[i];
		}
		cin >> target;
		dp[0] = 1;
		rep(i, 0, N) {
			rep(j, arr[i], target + 1) {
				dp[j] += dp[j - arr[i]];
			}
		}
		cout << dp[target] << '\n';
	}
}