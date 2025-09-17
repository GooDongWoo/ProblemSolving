#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using LL = long long;

int N, bit[100001], arr[100001], ans[100001];

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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	rep(i, 1, N + 1) {
		update(i, 1);
	}
	rep(i, 1, N + 1) {
		cin >> arr[i];
	}
	rep(i, 0, N) {
		int cur = N - i;
		int CntBig = cur - arr[cur];
		int start = 1, end = N;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (query(mid) < CntBig) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		update(start, -1);
		ans[start] = cur;
	}
	rep(i, 1, N + 1) {
		cout << ans[i] << ' ';
	}
	return 0;
}