#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

const int MAX = 100000;
int N, D, arr[MAX + 1];

template<class T>
class SegTree {
public:
	T segtree[4 * (MAX + 1)];
	T Identity;
	T(*func)(T, T);
	SegTree(T a, T(*b)(T, T)) : Identity(a), func(b) {
	}
	void init(int idx, int l, int r) {
		if (l == r) {
			segtree[idx] = arr[l];
			return;
		}
		int mid = (l + r) / 2;
		init(2 * idx, l, mid);
		init(2 * idx + 1, mid + 1, r);
		segtree[idx] = func(segtree[2 * idx], segtree[2 * idx + 1]);
		return;
	}

	void update(int idx, int l, int r, int qidx, T val) {
		if (qidx<l || qidx>r) {
			return;
		}
		if (l == r) {
			segtree[idx] += val;
			return;
		}
		int mid = (l + r) / 2;
		update(2 * idx, l, mid, qidx, val);
		update(2 * idx + 1, mid + 1, r, qidx, val);
		segtree[idx] = func(segtree[2 * idx], segtree[2 * idx + 1]);
		return;
	}

	T query(int idx, int l, int r, int ql, int qr) {
		if (qr<l || ql>r) {
			return Identity;
		}
		if (ql <= l && r <= qr) {
			return segtree[idx];
		}
		int mid = (l + r) / 2;
		T leftVal = query(2 * idx, l, mid, ql, qr);
		T rightVal = query(2 * idx + 1, mid + 1, r, ql, qr);
		return func(leftVal, rightVal);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> D;
	rep(i, 1, N + 1) {
		cin >> arr[i];
	}
	SegTree<LL> dp(~((LL)0), [](LL a, LL b) {return max(a, b); });
	dp.init(1, 1, N);
	rep(i, 2, N + 1) {
		int left = max(1, i - D);
		LL BefMaxDp = dp.query(1, 1, N, left, i - 1);
		if (BefMaxDp > 0) {
			dp.update(1, 1, N, i, BefMaxDp);
		}
	}
	cout << dp.query(1, 1, N, 1, N);
	return 0;
}