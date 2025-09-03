#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, arr[100001], M;
vector<int> mergeSortTree[400004];

void init(int idx, int l, int r) {
	if (l == r) {
		mergeSortTree[idx] = { arr[l] };
		return;
	}
	int mid = (l + r) / 2;
	init(2 * idx, l, mid);
	init(2 * idx + 1, mid + 1, r);
	mergeSortTree[idx].resize(mergeSortTree[2 * idx].size() + mergeSortTree[2 * idx + 1].size());
	merge(mergeSortTree[2 * idx].begin(), mergeSortTree[2 * idx].end(),
		mergeSortTree[2 * idx + 1].begin(), mergeSortTree[2 * idx + 1].end(),
		mergeSortTree[idx].begin());
}

int query(int idx, int l, int r, int ql, int qr, int val) {
	if (r < ql || qr < l) {
		return 0;
	}
	if (ql <= l && r <= qr) {
		int num = upper_bound(mergeSortTree[idx].begin(), mergeSortTree[idx].end(), val) - mergeSortTree[idx].begin();
		return num;
	}
	int mid = (l + r) / 2;
	int leftVal = query(2 * idx, l, mid, ql, qr, val);
	int rightVal = query(2 * idx + 1, mid + 1, r, ql, qr, val);
	return leftVal + rightVal;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	rep(i, 1, N + 1) {
		cin >> arr[i];
	}
	init(1, 1, N);
	rep(i, 0, M) {
		int ql, qr, target;
		cin >> ql >> qr >> target;
		int start = -1e9, end = 1e9;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (query(1, 1, N, ql, qr, mid) < target) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		cout << start << '\n';
	}

	return 0;
}