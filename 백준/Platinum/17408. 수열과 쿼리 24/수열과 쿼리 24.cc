#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, arr[100001], M, segtree[400004][2];

void init(int idx, int l, int r) {
	if (l == r) {
		segtree[idx][0] = arr[l];
		return;
	}
	int mid = (l + r) / 2;
	init(2 * idx, l, mid);
	init(2 * idx + 1, mid + 1, r);

	int tmp[4];
	tmp[0] = segtree[2 * idx][0];
	tmp[1] = segtree[2 * idx][1];
	tmp[2] = segtree[2 * idx + 1][0];
	tmp[3] = segtree[2 * idx + 1][1];
	sort(tmp, tmp + 4);
	segtree[idx][0] = tmp[3];
	segtree[idx][1] = tmp[2];
}

void update(int idx, int l, int r, int qidx, int val) {
	if (qidx<l || qidx>r) {
		return;
	}
	if (l == r) {
		segtree[idx][0] = val;
		return;
	}
	int mid = (l + r) / 2;
	update(2 * idx, l, mid, qidx, val);
	update(2 * idx + 1, mid + 1, r, qidx, val);

	int tmp[4];
	tmp[0] = segtree[2 * idx][0];
	tmp[1] = segtree[2 * idx][1];
	tmp[2] = segtree[2 * idx + 1][0];
	tmp[3] = segtree[2 * idx + 1][1];
	sort(tmp, tmp + 4);
	segtree[idx][0] = tmp[3];
	segtree[idx][1] = tmp[2];
}

pair<int, int> query(int idx, int l, int r, int ql, int qr) {
	if (qr<l || ql>r) {
		return { 0,0 };
	}
	if (ql <= l && r <= qr) {
		return { segtree[idx][0] ,segtree[idx][1] };
	}

	int mid = (l + r) / 2;
	auto leftVal = query(2 * idx, l, mid, ql, qr);
	auto rightVal = query(2 * idx + 1, mid + 1, r, ql, qr);

	int tmp[4];
	tmp[0] = leftVal.first;
	tmp[1] = leftVal.second;
	tmp[2] = rightVal.first;
	tmp[3] = rightVal.second;
	sort(tmp, tmp + 4);
	return { tmp[3],tmp[2] };
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	rep(i, 1, N + 1) {
		cin >> arr[i];
	}
	init(1,1,N);
	cin >> M;
	rep(i, 0, M) {
		int ctype;
		cin >> ctype;
		if (ctype == 1) {
			int idx, val;
			cin >> idx >> val;
			update(1, 1, N, idx, val);
		}
		else {
			int start, end;
			cin >> start >> end;
			auto curv = query(1, 1, N, start, end);
			cout << curv.first + curv.second << '\n';
		}
	}
	return 0;
}