#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

const int MAX = 100000;
const int MOD = 1e9 + 7;
int N, M, arr[MAX + 1];

template<class T>
class LazySeg {
public:
	T segtree[4 * (MAX + 1)];
	T lazy[4 * (MAX + 1)][2];
	T Identity;
	T(*func)(T, T);

	LazySeg(T a, T(*b)(T, T)) :Identity(a), func(b) {
		memset(segtree, 0, sizeof(segtree));
		memset(lazy, 0, sizeof(lazy));
		rep(i, 1, 4 * (MAX + 1)) {
			lazy[i][0] = 1;
		}
	}

	void lazyprop(int idx, int l, int r) {
		if (lazy[idx][0] == 1 && lazy[idx][1] == 0) {
			return;
		}
		if (l == r) {
			segtree[idx] = (((lazy[idx][0] * segtree[idx]) % MOD) + lazy[idx][1]) % MOD;
			lazy[idx][0] = 1;
			lazy[idx][1] = 0;
			return;
		}
		int cnt = r - l + 1;
		int mid = (l + r) / 2;
		segtree[idx] = ((lazy[idx][0] * segtree[idx]) % MOD + (lazy[idx][1] * cnt) % MOD) % MOD;

		lazy[2 * idx][0] = (lazy[idx][0] * lazy[2 * idx][0]) % MOD;
		lazy[2 * idx][1] = ((lazy[idx][0] * lazy[2 * idx][1]) % MOD + lazy[idx][1]) % MOD;

		lazy[2 * idx + 1][0] = (lazy[idx][0] * lazy[2 * idx + 1][0]) % MOD;
		lazy[2 * idx + 1][1] = ((lazy[idx][0] * lazy[2 * idx + 1][1]) % MOD + lazy[idx][1]) % MOD;

		lazy[idx][0] = 1;
		lazy[idx][1] = 0;
		return;
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

	void update(int idx, int l, int r, int ql, int qr, T v1, T v2) {
		lazyprop(idx, l, r);
		if (r < ql || qr < l) {
			return;
		}
		if (ql <= l && r <= qr) {
			lazy[idx][0] = (lazy[idx][0] * v1) % MOD;
			lazy[idx][1] = ((lazy[idx][1] * v1) % MOD + v2) % MOD;
			lazyprop(idx, l, r);
			return;
		}
		int mid = (l + r) / 2;
		update(2 * idx, l, mid, ql, qr, v1, v2);
		update(2 * idx + 1, mid + 1, r, ql, qr, v1, v2);
		segtree[idx] = func(segtree[2 * idx], segtree[2 * idx + 1]);
		return;
	}

	T query(int idx, int l, int r, int ql, int qr) {
		lazyprop(idx, l, r);
		if (r < ql || qr < l) {
			return Identity;
		}
		if (ql <= l && r <= qr) {
			return segtree[idx];
		}
		int mid = (l + r) / 2;
		return func(query(2 * idx, l, mid, ql, qr), query(2 * idx + 1, mid + 1, r, ql, qr));
	}
};

LazySeg<LL> lazyseg(0, [](LL a, LL b) {return (a + b) % MOD; });

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	rep(i, 1, N + 1) {
		cin >> arr[i];
	}
	lazyseg.init(1, 1, N);
	cin >> M;
	rep(i, 0, M) {
		int cmd, start, end, val;
		cin >> cmd >> start >> end;
		if (cmd == 1) {
			cin >> val;
			lazyseg.update(1, 1, N, start, end, 1, val);
		}
		else if (cmd == 2) {
			cin >> val;
			lazyseg.update(1, 1, N, start, end, val, 0);
		}
		else if (cmd == 3) {
			cin >> val;
			lazyseg.update(1, 1, N, start, end, 0, val);
		}
		else {
			cout << lazyseg.query(1, 1, N, start, end) << '\n';
		}
	}
	return 0;
}