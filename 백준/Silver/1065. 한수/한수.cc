#include <iostream>
#include <algorithm>
#include <string>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, dp[1001];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	rep(i, 1, 10) {
		dp[i] = dp[i - 1] + 1;
	}
	rep(i, 10, 1001) {
		string cur = to_string(i);
		int n = cur.size();
		if (n == 2) {
			dp[i] = dp[i - 1] + 1;
		}
		else {
			int incre = cur[1] - cur[0];
			int idx = 2;
			bool Flag = 1;
			while (idx < n) {
				if (cur[idx]-cur[idx-1] != incre) {
					Flag = 0;
					break;
				}
				idx++;
			}
			if (Flag) {
				dp[i] = dp[i - 1] + 1;
			}
			else {
				dp[i] = dp[i - 1];
			}
		}
	}
	cin >> N;
	cout << dp[N];

	return 0;
}