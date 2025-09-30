#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int N, pi[500][10000], cnt[500], dp[100001];
string ori, minis[500];
vector<int> arr;

void makeF(int step, string& mini) {
	int miniCnt = 0;
	rep(cur, 1, mini.size()) {
		while (miniCnt > 0 && mini[cur] != mini[miniCnt]) {
			miniCnt = pi[step][miniCnt - 1];
		}
		if (mini[cur] == mini[miniCnt]) {
			miniCnt++;
		}
		pi[step][cur] = miniCnt;
	}
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> ori;
	cin >> N;
	rep(i, 0, N) {
		cin >> minis[i];
		makeF(i, minis[i]);
	}
	rep(cur, 0, ori.size()) {
		rep(step, 0, N) {
			while (cnt[step] > 0 && ori[cur] != minis[step][cnt[step]]) {
				cnt[step] = pi[step][cnt[step] - 1];
			}
			if (ori[cur] == minis[step][cnt[step]]) {
				cnt[step]++;
			}
			if (cnt[step] == minis[step].size()) {
				arr.push_back(minis[step].size());
				cnt[step] = pi[step][cnt[step] - 1];
			}
		}
		for (const int len : arr) {
			if (cur - len + 1 == 0) {
				dp[cur] = max(dp[cur], len);
			}
			else {
				dp[cur] = max(dp[cur], len + dp[cur - len]);
			}
		}
		if (cur > 0) {
			dp[cur] = max(dp[cur], dp[cur - 1]);
		}
		arr.clear();
	}
	cout << dp[ori.size() - 1];
	return 0;
}