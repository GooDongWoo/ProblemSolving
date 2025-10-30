#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N,res;
LL dp[100][21];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	int sval;
	cin >> sval;
	dp[0][sval] = 1;
	rep(i, 1, N - 1) {
		cin >> sval;
		rep(j, 0, 21) {
			if (0 <= j - sval) {
				dp[i][j - sval] += dp[i - 1][j];
			}
			if (j + sval <= 20) {
				dp[i][j + sval] += dp[i - 1][j];
			}
		}
	}
	cin >> res;
	cout << dp[N - 2][res];
	return 0;
}