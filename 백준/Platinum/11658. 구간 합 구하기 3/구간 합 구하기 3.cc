#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, M, arr[1025][1025];
LL segtree[4100][1025];

void init(int idx, int l, int r) {
	if (l == r) {
		rep(i, 1, N + 1) {
			segtree[idx][i] = arr[l][i];
		}
		return;
	}
	int mid = (l + r) / 2;
	init(2 * idx, l, mid);
	init(2 * idx + 1, mid + 1, r);
	rep(i, 1, N + 1) {
		segtree[idx][i] = segtree[2 * idx][i] + segtree[2 * idx + 1][i];
	}
	return;
}

void update(int idx, int l, int r, int x, int y, int val) {
	if (x < l || r < x) {
		return;
	}
	if (l == r) {
		segtree[idx][y] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(2 * idx, l, mid, x, y, val);
	update(2 * idx + 1, mid + 1, r, x, y, val);
	segtree[idx][y] = segtree[2 * idx][y] + segtree[2 * idx + 1][y];
	return;
}

LL query(int idx, int l, int r, int x1, int y1, int x2, int y2) {
	if (x2 < l || r < x1) {
		return 0;
	}
	if (x1 <= l && r <= x2) {
		LL tmp = 0;
		rep(i, y1, y2 + 1) {
			tmp += segtree[idx][i];
		}
		return tmp;
	}
	int mid = (l + r) / 2;
	LL leftVal = query(2 * idx, l, mid, x1, y1, x2, y2);
	LL rightVal = query(2 * idx + 1, mid + 1, r, x1, y1, x2, y2);
	return leftVal + rightVal;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	rep(i, 1, N + 1) {
		rep(j, 1, N + 1) {
			cin >> arr[i][j];
		}
	}
	init(1, 1, N);
	rep(i, 0, M) {
		int W;
		cin >> W;
		if (W == 0) {
			int x, y, c;
			cin >> x >> y >> c;
			update(1, 1, N, x, y, c);
		}
		else {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << query(1, 1, N, x1, y1, x2, y2) << '\n';
		}
	}
	return 0;
}