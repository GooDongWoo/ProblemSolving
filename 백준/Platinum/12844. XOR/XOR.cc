#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

#define SIZE 500001

LL arr[SIZE], segarr[4 * SIZE], lazy[4 * SIZE], N, M;

struct segtree {
	LL init(LL sidx, LL left, LL right) {
		if (left == right) {
			segarr[sidx] = arr[left];
			return arr[left];
		}
		LL mid = (left + right) / 2;
		LL leftVal = init(2 * sidx, left, mid);
		LL rightVal = init(2 * sidx + 1, mid + 1, right);
		return segarr[sidx] = leftVal ^ rightVal;
	}
	void lazyProp(LL sidx, LL left, LL right) {
		if (lazy[sidx]) {
			if ((right - left + 1) % 2 == 1) {
				segarr[sidx] ^= lazy[sidx];
			}
			if (left != right) {
				lazy[2 * sidx] ^= lazy[sidx];
				lazy[2 * sidx + 1] ^= lazy[sidx];
			}
			lazy[sidx] = 0;
		}
		return;
	}
	LL query(LL sidx, LL qleft, LL qright, LL left, LL right) {

		lazyProp(sidx, left, right);

		if (qright < left || right < qleft) {
			return 0;
		}
		if (qleft <= left && right <= qright) {
			return segarr[sidx];
		}
		LL mid = (left + right) / 2;
		LL leftVal = query(sidx * 2, qleft, qright, left, mid);
		LL rightVal = query(sidx * 2 + 1, qleft, qright, mid + 1, right);
		return leftVal ^ rightVal;
	}
	void update(LL sidx, LL qleft, LL qright, LL left, LL right, LL val) {

		lazyProp(sidx, left, right);

		if (qright < left || right < qleft) {
			return;
		}
		if (qleft <= left && right <= qright) {
			if ((right - left + 1) % 2 == 1) {
				segarr[sidx] ^= val;
			}
			if (left != right) {
				lazy[2 * sidx] ^= val;
				lazy[2 * sidx + 1] ^= val;
			}
			return;
		}
		LL mid = (left + right) / 2;
		update(2 * sidx, qleft, qright, left, mid, val);
		update(2 * sidx + 1, qleft, qright, mid + 1, right, val);
		segarr[sidx] = segarr[2 * sidx] ^ segarr[2 * sidx + 1];
		return;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	rep(i, 1, N + 1) {
		cin >> arr[i];
	}
	segtree seg;
	seg.init(1, 1, N);
	cin >> M;
	rep(i, 0, M) {
		LL a, b, c, d;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d; 
			b++; c++;
			seg.update(1, b, c, 1, N, d);
		}
		else {
			cin >> b >> c;
			b++; c++;
			cout << seg.query(1, b, c, 1, N) << '\n';
		}
	}
	return 0;
}