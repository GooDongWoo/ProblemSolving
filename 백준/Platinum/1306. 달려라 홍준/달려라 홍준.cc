#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;


int N, M, arr[1000001], segtree[4000004];

void init(int idx, int l, int r) {
	if (l == r) {
		segtree[idx] = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	init(2 * idx, l, mid);
	init(2 * idx + 1, mid + 1, r);
	segtree[idx] = max(segtree[2 * idx], segtree[2 * idx + 1]);
	return;
}

void update(int idx, int l, int r, int qidx, int val) {
	if (qidx<l || qidx>r) {
		return;
	}
	if (l == r) {
		segtree[idx] = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	update(2 * idx, l, mid, qidx, val);
	update(2 * idx + 1, mid + 1, r, qidx, val);
	segtree[idx] = max(segtree[2 * idx], segtree[2 * idx + 1]);
	return;
}

int query(int idx, int l, int r, int ql, int qr) {
	if (qr<l || ql>r) {
		return 0;
	}
	if (ql <= l && r <= qr) {
		return segtree[idx];
	}
	int mid = (l + r) / 2;
	int leftVal = query(2 * idx, l, mid, ql, qr);
	int rightVal = query(2 * idx + 1, mid + 1, r, ql, qr);
	return max(leftVal, rightVal);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	rep(i, 1, N + 1) {
		cin >> arr[i];
	}
	init(1, 1, N);
	rep(i, M, N - M + 2) {
		cout << query(1, 1, N, i - M + 1, i + M - 1) << ' ';
	}
	return 0;
}