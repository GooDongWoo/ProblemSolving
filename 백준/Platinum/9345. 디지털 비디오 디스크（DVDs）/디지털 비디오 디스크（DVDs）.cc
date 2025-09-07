#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

int T, N, K, arr[100001], stMax[400004], stMin[400004];

void initMax(int idx, int l, int r) {
	if (l == r) {
		stMax[idx] = l;
		return;
	}
	int mid = (l + r) / 2;
	initMax(2 * idx, l, mid);
	initMax(2 * idx + 1, mid + 1, r);
	stMax[idx] = max(stMax[2 * idx], stMax[2 * idx + 1]);
	return;
}

void updateMax(int idx, int l, int r, int qidx, int val) {
	if (qidx<l || qidx>r) {
		return;
	}
	if (l == r) {
		stMax[idx] = val;
		return;
	}
	int mid = (l + r) / 2;
	updateMax(2 * idx, l, mid, qidx, val);
	updateMax(2 * idx + 1, mid + 1, r, qidx, val);
	stMax[idx] = max(stMax[2 * idx], stMax[2 * idx + 1]);
	return;
}

int queryMax(int idx, int l, int r, int ql, int qr) {
	if (r < ql || qr < l) {
		return 0;
	}
	if (ql <= l && r <= qr) {
		return stMax[idx];
	}
	int mid = (l + r) / 2;
	int leftVal = queryMax(2 * idx, l, mid, ql, qr);
	int rightVal = queryMax(2 * idx + 1, mid + 1, r, ql, qr);
	return max(leftVal, rightVal);
}

void initMin(int idx, int l, int r) {
	if (l == r) {
		stMin[idx] = l;
		return;
	}
	int mid = (l + r) / 2;
	initMin(2 * idx, l, mid);
	initMin(2 * idx + 1, mid + 1, r);
	stMin[idx] = min(stMin[2 * idx], stMin[2 * idx + 1]);
	return;
}

void updateMin(int idx, int l, int r, int qidx, int val) {
	if (qidx<l || qidx>r) {
		return;
	}
	if (l == r) {
		stMin[idx] = val;
		return;
	}
	int mid = (l + r) / 2;
	updateMin(2 * idx, l, mid, qidx, val);
	updateMin(2 * idx + 1, mid + 1, r, qidx, val);
	stMin[idx] = min(stMin[2 * idx], stMin[2 * idx + 1]);
	return;
}

int queryMin(int idx, int l, int r, int ql, int qr) {
	if (r < ql || qr < l) {
		return 1e9;
	}
	if (ql <= l && r <= qr) {
		return stMin[idx];
	}
	int mid = (l + r) / 2;
	int leftVal = queryMin(2 * idx, l, mid, ql, qr);
	int rightVal = queryMin(2 * idx + 1, mid + 1, r, ql, qr);
	return min(leftVal, rightVal);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	rep(test_case, 1, T + 1) {
		cin >> N >> K;
		memset(stMax, 0, sizeof(stMax));
		memset(stMin, 0, sizeof(stMin));
		rep(i, 1, N + 1) {
			arr[i] = i;
		}
		initMax(1, 1, N);
		initMin(1, 1, N);
		rep(i, 0, K) {
			int Q, A, B;
			cin >> Q >> A >> B; A++; B++;
			if (Q == 0) {
				updateMax(1, 1, N, A, arr[B]);
				updateMin(1, 1, N, A, arr[B]);

				updateMax(1, 1, N, B, arr[A]);
				updateMin(1, 1, N, B, arr[A]);
				swap(arr[A], arr[B]);
			}
			else {
				int l = queryMin(1, 1, N, A, B);
				int r = queryMax(1, 1, N, A, B);
				if (l == A && r == B) {
					cout << "YES\n";
				}
				else {
					cout << "NO\n";
				}
			}
		}
	}
	return 0;
}