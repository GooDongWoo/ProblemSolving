#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i,a,b) for(int i=a;i<b;++i)

using namespace std;

long long T, N, dp[1000001], MOD = 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	rep(i, 3, 1000001) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	}
	cin >> T;
	rep(test_case, 1, T + 1) {
		cin >> N;
		cout << dp[N] << "\n";
	}
}