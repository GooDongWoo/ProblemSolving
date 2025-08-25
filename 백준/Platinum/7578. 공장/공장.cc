#include <iostream>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, arr[500001], dat[1000001];
LL ans;

void update(int idx, int val) {
	while (idx <= N) {
		arr[idx] += val;
		idx += idx & (~idx + 1);
	}
}

int query(int idx) {
	int cur = 0;
	while (idx > 0) {
		cur += arr[idx];
		idx -= idx & (~idx + 1);
	}
	return cur;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	rep(i, 1, N + 1) {
		int a;
		cin >> a;
		dat[a] = i;
	}
	rep(i, 0, N) {
		int a;
		cin >> a;
		ans += (LL)(i - query(dat[a]));
		update(dat[a], 1);
	}
	cout << ans;
	return 0;
}