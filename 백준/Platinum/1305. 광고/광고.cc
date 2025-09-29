#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int L, dp[1000000];
string word;

void makeDP() {
	int cnt = 0;
	rep(cur, 1, L) {
		while (cnt > 0 && word[cur] != word[cnt]) {
			cnt = dp[cnt - 1];
		}
		if (word[cur] == word[cnt]) {
			cnt++;
		}
		dp[cur] = cnt;
	}
	return;
}

void solve() {
	if (dp[L - 1] == 0) {
		cout << L;
	}
	else {
		cout << L - dp[L - 1];
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> L;
	cin >> word;
	makeDP();
	solve();
	return 0;
}