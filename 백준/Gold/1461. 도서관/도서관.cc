#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;
using LL = long long;

int N, M, arr[50], ans;
vector<int> pos, neg;

int main() {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> M;
	rep(i, 0, N) {
		int a;
		cin >> a;
		if (a > 0) pos.push_back(a);
		else neg.push_back(a);
	}
	sort(neg.begin(), neg.end());
	sort(pos.begin(), pos.end(), greater<>());
	vector<int> candis;
	int maxval = 0;
	rep(i, 0, neg.size()) {
		if (i % M == 0) {
			ans += -2 * neg[i];
		}
	}
	rep(i, 0, pos.size()) {
		if (i % M == 0) {
			ans += 2 * pos[i];
		}
	}
	if (neg.size()) {
		maxval = max(maxval, -neg[0]);
	}
	if (pos.size()) {
		maxval = max(maxval, pos[0]);
	}
	cout << ans - maxval;
	return 0;
}