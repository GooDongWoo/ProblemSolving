#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, arr[1000001], bit[4000004];
LL ans;

void update(int idx, int val) {
	while (idx <= N) {
		bit[idx] += val;
		idx += idx & -idx;
	}
	return;
}

int query(int idx) {
	int ret = 0;
	while (idx > 0) {
		ret += bit[idx];
		idx -= idx & -idx;
	}
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	rep(i, 0, N) {
		int a;
		cin >> a;
		ans += i - query(a);
		update(a, 1);
	}
	cout << ans;
	return 0;
}