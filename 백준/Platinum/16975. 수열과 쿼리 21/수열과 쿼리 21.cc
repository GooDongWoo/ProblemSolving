#include <iostream>
#include <algorithm>
#include <unordered_map>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, arr[100001], M;
LL segtree[400004], lazy[400004];

void init(int idx, int l, int r) {
	if (l == r) {
		segtree[idx] = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	init(2 * idx, l, mid);
	init(2 * idx + 1, mid + 1, r);
	segtree[idx] = segtree[2 * idx] + segtree[2 * idx + 1];
}

void lazyprop(int idx, int l, int r) {
	if (lazy[idx] == 0) {
		return;
	}
	segtree[idx] += lazy[idx] * (r - l + 1);
	if (l != r) {
		lazy[2 * idx] += lazy[idx];
		lazy[2 * idx + 1] += lazy[idx];
	}
	lazy[idx] = 0;
}

void update(int idx, int l, int r, int ql, int qr, int val) {
	lazyprop(idx, l, r);
	if (r < ql || qr < l) {
		return;
	}
	if (ql <= l && r <= qr) {
		lazy[idx] += val;
		return;
	}
	if (ql <= r) {
		segtree[idx] += val * (r - ql + 1);
	}
	else {
		segtree[idx] += val * (qr - l + 1);
	}
	int mid = (l + r) / 2;
	update(2 * idx, l, mid, ql, qr, val);
	update(2 * idx + 1, mid + 1, r, ql, qr, val);
	return;
}

LL query(int idx, int l, int r, int ql, int qr) {
	lazyprop(idx, l, r);
	if (r < ql || qr < l) {
		return 0;
	}
	if (ql <= l && r <= qr) {
		return segtree[idx];
	}
	int mid = (l + r) / 2;
	LL leftVal = query(2 * idx, l, mid, ql, qr);
	LL rightVal = query(2 * idx + 1, mid + 1, r, ql, qr);
	return leftVal + rightVal;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	rep(i, 1, N + 1) {
		cin >> arr[i];
	}
	init(1, 1, N);
	cin >> M;
	rep(i, 0, M) {
		int ctype;
		cin >> ctype;
		if (ctype == 1) {
			int start, end, val;
			cin >> start >> end >> val;
			update(1, 1, N, start, end, val);
		}
		else {
			int start;
			cin >> start;
			cout << query(1, 1, N, start, start) << '\n';
		}
	}
	return 0;
}