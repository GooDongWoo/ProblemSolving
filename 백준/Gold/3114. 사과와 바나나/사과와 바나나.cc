#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define LL long long

const int MAX_SIZE = 1502;

LL R, C;
LL apple[MAX_SIZE][MAX_SIZE], banana[MAX_SIZE][MAX_SIZE];
LL lsum[MAX_SIZE][MAX_SIZE], rsum[MAX_SIZE][MAX_SIZE];
LL dp[2][MAX_SIZE][MAX_SIZE];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C;

	string tmp;
	rep(i, 1, R + 1) {
		rep(j, 1, C + 1) {
			cin >> tmp;
			if (tmp[0] == 'A') 
				lsum[i][j] = stoi(tmp.substr(1));
			else 
				rsum[i][j] = stoi(tmp.substr(1));
		}
	}
	rep(i, 1, R + 1) {
		rep(j, 2, C + 1) {
			lsum[i][j] += lsum[i][j - 1];
			rsum[i][C - j + 1] += rsum[i][C - j + 2];
		}
	}

	dp[0][1][1] = 0;
	dp[1][1][1] = rsum[1][2];
	rep(j,2,C+1)
		dp[1][1][j] = dp[1][1][j - 1] - (rsum[1][j] - rsum[1][j + 1]);
	rep(i, 2, R + 1)
		dp[1][i][1] = dp[1][i - 1][1] + rsum[i][2];

	rep(i, 2, R + 1) {
		rep(j, 2, C + 1) {
			LL a = 0, b = 0, c = 0;
			//U
			a += dp[0][i - 1][j] + lsum[i][j - 1];
			a += dp[1][i - 1][j] + rsum[i][j + 1];
			//LU
			b += dp[0][i - 1][j - 1] + lsum[i][j - 1];
			b += dp[1][i - 1][j - 1] + rsum[i][j + 1];

			//L
			c += dp[0][i][j - 1];
			c += dp[1][i][j - 1] - (rsum[i][j] - rsum[i][j + 1]);
			if (max({ a, b, c }) == a) {
				dp[0][i][j] = dp[0][i - 1][j] + lsum[i][j - 1];
				dp[1][i][j] = dp[1][i - 1][j] + rsum[i][j + 1];
			}
			else if (max({ a, b, c }) == b) {
				dp[0][i][j] = dp[0][i - 1][j - 1] + lsum[i][j - 1];
				dp[1][i][j] = dp[1][i - 1][j - 1] + rsum[i][j + 1];
			}
			else {
				dp[0][i][j] = dp[0][i][j - 1];
				dp[1][i][j] = dp[1][i][j - 1] - (rsum[i][j] - rsum[i][j + 1]);
			}
		}
	}

	cout << dp[0][R][C] + dp[1][R][C];

	return 0;
}