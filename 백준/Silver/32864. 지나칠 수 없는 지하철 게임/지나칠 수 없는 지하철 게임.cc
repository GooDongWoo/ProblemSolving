#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;

int N;
bool arr[500000];
vector<int> compressed;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	compressed.reserve(N);
	rep(i, 0, N) {
		cin >> arr[i];
	}
	if (N == 2) {
		cout << "mnx";
		return 0;
	}
	compressed.push_back(arr[1]);
	rep(i, 2, N - 1) {
		if (!(compressed.back() == 0 && arr[i] == 0)) {
			compressed.push_back(arr[i]);
		}
	}
	while (compressed.size() && compressed.back() == 0) {
		compressed.pop_back();
	}
	N = compressed.size();
	if (N == 0) {
		cout << "mnx";
		return 0;
	}
	vector<bool> dp(N);
	for (int i = N - 2; i > -1; --i) {
		if (i + 2 < N) {
			if (compressed[i] == 0) {
				dp[i] = !dp[i + 1];
			}
			else {
				if (compressed[i + 1] == 1) {
					dp[i] = !dp[i + 1];
				}
				else {
					dp[i] = 0;
				}
			}
		}
		else {
			dp[i] = 1;
		}
	}
	if (dp[0] == 1 || (compressed[0] == 0 && dp[1] == 1)) {
		cout << "mnx";
	}
	else {
		cout << "alsdkffhgk";
	}
	return 0;
}