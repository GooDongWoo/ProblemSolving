#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

LL N, arr[500001], ans;
unordered_map<LL, LL> dict;

void update(LL idx, LL val) {
	while (idx <= N) {
		arr[idx] += val;
		idx += idx & (~idx + 1);
	}
}

LL query(LL idx) {
	LL cur = 0;
	while (idx > 0) {
		cur += arr[idx];
		idx -= idx & (~idx + 1);
	}
	return cur;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	dict.reserve(N);
	rep(i, 1, N + 1) {
		LL a;
		cin >> a;
		dict[a] = i;
	}
	rep(i, 0, N) {
		LL a;
		cin >> a;
		ans += (i - query(dict[a]));
		update(dict[a], 1);
	}
	cout << ans;
	return 0;
}