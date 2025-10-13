#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, dp[1500001];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	rep(i, 1, N + 1) {
		int time, money;
		cin >> time >> money; time--;
		if (i + time < N + 1) {
			dp[i + time] = max(dp[i + time], dp[i - 1] + money);
		}
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[N];
	return 0;
}
