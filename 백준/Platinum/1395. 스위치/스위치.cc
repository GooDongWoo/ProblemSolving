#include <iostream>
#include <algorithm>
#include <unordered_map>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, M, segtree[400004], lazy[400004];

void lazyprop(int idx, int l, int r) {
	if (lazy[idx] == 0) {
		return;
	}
	segtree[idx] = (r - l + 1) - segtree[idx];
	if (l != r) {
		lazy[2 * idx] ^= 1;
		lazy[2 * idx + 1] ^= 1;
	}
	lazy[idx] = 0;
}

void update(int idx, int l, int r, int ql, int qr, int val) {
	lazyprop(idx, l, r);
	if (r < ql || qr < l) {
		return;
	}
	if (ql <= l && r <= qr) {
		lazy[idx] ^= val;
		lazyprop(idx, l, r);
		return;
	}
	int mid = (l + r) / 2;
	update(2 * idx, l, mid, ql, qr, val);
	update(2 * idx + 1, mid + 1, r, ql, qr, val);
	segtree[idx] = segtree[2 * idx] + segtree[2 * idx + 1];
	return;
}

int query(int idx, int l, int r, int ql, int qr) {
	lazyprop(idx, l, r);
	if (r < ql || qr < l) {
		return 0;
	}
	if (ql <= l && r <= qr) {
		return segtree[idx];
	}
	int mid = (l + r) / 2;
	int leftVal = query(2 * idx, l, mid, ql, qr);
	int rightVal = query(2 * idx + 1, mid + 1, r, ql, qr);
	return leftVal + rightVal;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	rep(i, 0, M) {
		int ctype, start, end;
		cin >> ctype >> start >> end;
		if (ctype == 0) {
			update(1, 1, N, start, end, 1);
		}
		else {
			cout << query(1, 1, N, start, end) << '\n';
		}
	}
	return 0;
}