#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int L, dp[5000], ans;

void makeDP(const string& word) {
	int cnt = 0;
	rep(cur, 1, word.size()) {
		while (cnt > 0 && word[cur] != word[cnt]) {
			cnt = dp[cnt - 1];
		}
		if (word[cur] == word[cnt]) {
			cnt++;
		}
		dp[cur] = cnt;
		ans = max(ans, dp[cur]);
	}
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	string name;
	cin >> name;
	rep(i, 0, name.size()) {
		makeDP(name.substr(i, name.size()));
	}
	cout << ans;
	return 0;
}