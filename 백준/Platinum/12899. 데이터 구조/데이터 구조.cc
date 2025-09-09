#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;

const int MAX = 2000001;
int N, bit[MAX];

void update(int idx, int val) {
	while (idx < MAX) {
		bit[idx] += val;
		idx += idx & -idx;
	}
	return;
}

int query(int idx) {
	int ret = 0;
	while (idx > 0) {
		ret += bit[idx];
		idx -= idx & -idx;
	}
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	rep(i, 0, N) {
		int T, X;
		cin >> T >> X;
		if (T == 1) {
			update(X, 1);
		}
		else {
			int start = 1, end = MAX - 1;
			while (start <= end) {
				int mid = (start + end) / 2;
				if (query(mid) < X) {
					start = mid + 1;
				}
				else {
					end = mid - 1;
				}
			}
			cout << start << '\n';
			update(start, -1);
		}
	}
	return 0;
}