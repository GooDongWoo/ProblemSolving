#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

#define MOD 1000000007
string arr;
LL dp[100000], psum[100000], ans;

int main() {
	fastio;
	cin >> arr;
	int N = arr.size();

	dp[0] = 1;
	psum[0] = 1;

	rep(i, 1, N) {
		dp[i] = (psum[i - 1] + 1) % MOD;
		psum[i] = (psum[i - 1] + dp[i]) % MOD;
	}
	rep(i, 0, N) {
		if (arr[i] == 'O') {
			ans = (ans + dp[i]) % MOD;
		}
	}
	printf("%lld", ans);
	return 0;
}