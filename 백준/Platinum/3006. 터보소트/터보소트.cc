#define rep(i,a,b) for(int i=a;i<b;++i)
#define LL long long
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_set>
using namespace std;

#define SIZE 100001
int N, arr[SIZE], segval[4 * SIZE];

struct segtree {
	void init(int sidx, int left, int right) {
		if (left == right) {
			segval[sidx] = 1;//arr[left];
		}
		else {
			int mid = (left + right) / 2;
			init(2 * sidx, left, mid);
			init(2 * sidx + 1, mid + 1, right);
			segval[sidx] = segval[2 * sidx] + segval[2 * sidx + 1];
		}
	}

	void update(int sidx, int idx, int val, int left, int right) {
		if (left == right) {
			//arr[left] = val;
			segval[sidx] = val;
		}
		else {
			int mid = (left + right) / 2;
			if (idx <= mid) {
				update(2 * sidx, idx, val, left, mid);
			}
			else {
				update(2 * sidx + 1, idx, val, mid + 1, right);
			}
			segval[sidx] = segval[2 * sidx] + segval[2 * sidx + 1];
		}
	}

	int query(int sidx, int qleft, int qright, int left, int right) {
		if (qleft > right || qright < left) {
			return 0;
		}
		if (qleft <= left && right <= qright) {
			return segval[sidx];
		}
		int mid = (left + right) / 2;
		int lval = query(2 * sidx, qleft, qright, left, mid);
		int rval = query(2 * sidx + 1, qleft, qright, mid + 1, right);
		return lval + rval;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	int a;
	rep(i, 1, N + 1) {
		cin >> a;
		arr[a] = i;
	}
	segtree seg;
	seg.init(1, 1, N);

	rep(i, 0, N / 2) {
		int idx;
		idx = arr[1 + i];

		seg.update(1, idx, 0, 1, N);
		cout << seg.query(1, 1, idx, 1, N) << '\n';


		idx = arr[N - i];

		seg.update(1, idx, 0, 1, N);
		cout << seg.query(1, idx, N, 1, N) << '\n';
	}
	if (N & 1) {
		int idx;
		idx = arr[N / 2 + 1];

		seg.update(1, idx, 0, 1, N);
		cout << seg.query(1, 1, idx, 1, N) << '\n';

	}

	return 0;
}