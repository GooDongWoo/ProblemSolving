#define rep(i,a,b) for(int i=a;i<b;++i)
#define LL long long
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_set>
using namespace std;

#define SIZE 100001
int T, N, M, segval[2 * 4 * SIZE], dict[SIZE];

struct segtree {
	void init(int sidx, int left, int right) {
		if (left == right) {
			if (left <= N) {
				segval[sidx] = 1;
			}
			else {
				segval[sidx] = 0;
			}
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
	cin >> T;
	rep(test_case, 1, T + 1) {
		cin >> N >> M;

		segtree seg;
		seg.init(1, 1, N + M);

		rep(i, 1, N + 1) {
			dict[i] = N + 1 - i;
		}

		int a;
		rep(i, 1, M + 1) {
			cin >> a;
			// 해당 위치부터 가장 위까지
			cout << seg.query(1, dict[a], N + M, 1, N + M) - 1 << ' ';

			// 해당 위치 세그를 0으로
			seg.update(1, dict[a], 0, 1, N + M);

			// N+i위치 세그를 1로 바꿈
			dict[a] = N + i;
			seg.update(1, dict[a], 1, 1, N + M);
		}
		cout << '\n';
	}
	return 0;
}