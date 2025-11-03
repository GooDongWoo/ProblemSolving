#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, dp[20][2][2];
vector<int> optrs;
vector<int> opnds;
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int (*funcs[3])(int, int) = { add,subtract,multiply };

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	rep(i, 0, N) {
		if (i & 1) {
			char a;
			cin >> a;
			if (a == '+') { optrs.push_back(0); }
			else if (a == '-') { optrs.push_back(1); }
			else if (a == '*') { optrs.push_back(2); }
		}
		else {
			int a;
			cin >> a;
			opnds.push_back(a);
		}
	}
	if (N == 1) {
		cout << opnds[0];
		return 0;
	}


	dp[0][0][0] = dp[0][0][1] = dp[0][1][0] = dp[0][1][1] = opnds[0];
	dp[1][0][0] = dp[1][0][1] = dp[1][1][0] = dp[1][1][1] = funcs[optrs[0]](opnds[0], opnds[1]);

	rep(i, 2, opnds.size()) {
		dp[i][0][0] = min(min(funcs[optrs[i - 1]](dp[i - 1][0][0], opnds[i]), funcs[optrs[i - 1]](dp[i - 1][0][1], opnds[i])),
			min(funcs[optrs[i - 1]](dp[i - 1][1][0], opnds[i]), funcs[optrs[i - 1]](dp[i - 1][1][1], opnds[i])));
		dp[i][0][1] = max(max(funcs[optrs[i - 1]](dp[i - 1][0][0], opnds[i]), funcs[optrs[i - 1]](dp[i - 1][0][1], opnds[i])),
			max(funcs[optrs[i - 1]](dp[i - 1][1][0], opnds[i]), funcs[optrs[i - 1]](dp[i - 1][1][1], opnds[i])));

		int aft = funcs[optrs[i - 1]](opnds[i - 1], opnds[i]);
		dp[i][1][0] = min(min(funcs[optrs[i - 2]](dp[i - 2][0][0], aft), funcs[optrs[i - 2]](dp[i - 2][0][1], aft)),
			min(funcs[optrs[i - 2]](dp[i - 2][1][0], aft), funcs[optrs[i - 2]](dp[i - 2][1][1], aft)));
		dp[i][1][1] = max(max(funcs[optrs[i - 2]](dp[i - 2][0][0], aft), funcs[optrs[i - 2]](dp[i - 2][0][1], aft)),
			max(funcs[optrs[i - 2]](dp[i - 2][1][0], aft), funcs[optrs[i - 2]](dp[i - 2][1][1], aft)));
	}
	cout << max(max(dp[opnds.size() - 1][0][0], dp[opnds.size() - 1][0][1]), max(dp[opnds.size() - 1][1][0], dp[opnds.size() - 1][1][1]));
	return 0;
}