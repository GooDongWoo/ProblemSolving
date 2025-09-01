#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <tuple>
#include <vector>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;
using namespace std;

struct Item {
	int x, y;
	bool operator<(const Item& b) const {
		return tie(b.x, y) < tie(x, b.y);
	}
};
int T, N, segtree[300004];
Item arr[75001];
unordered_map<int, int> dict;
LL ans;
vector<int> yVal;

void update(int idx, int l, int r, int qidx, int val) {
	if (r < qidx || qidx < l) {
		return;
	}
	if (l == r && l == qidx) {
		segtree[idx] += val;
		return;
	}
	int mid = (l + r) / 2;
	update(2 * idx, l, mid, qidx, val);
	update(2 * idx + 1, mid + 1, r, qidx, val);
	segtree[idx] = segtree[2 * idx] + segtree[2 * idx + 1];
}

int query(int idx, int l, int r, int ql, int qr) {
	if (r < ql || qr < l) {
		return 0;
	}
	if (ql <= l && r <= qr) {
		return segtree[idx];
	}
	int mid = (l + r) / 2;
	int leftVal = query(2 * idx, l, mid, ql, qr);
	int rightVal = query(2 * idx + 1, mid + 1, r, ql, qr);
	return leftVal + rightVal;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	rep(test_case, 0, T) {
		dict.clear();
		ans = 0;
		memset(segtree, 0, sizeof(segtree));

		cin >> N;
		dict.reserve(N);
		
		yVal.clear();
		yVal.resize(N);

		rep(i, 0, N) {
			cin >> arr[i].x >> arr[i].y;
			yVal[i] = arr[i].y;
		}
		sort(arr, arr + N);
		sort(yVal.begin(), yVal.end());
		yVal.erase(unique(yVal.begin(), yVal.end()),yVal.end());
		rep(i, 0, yVal.size()) {
			dict[yVal[i]] = i + 1;
		}
		rep(i, 0, N) {
			int mapping = dict[arr[i].y];
			ans += query(1, 1, N, 1, mapping);
			update(1, 1, N, mapping, 1);
		}
		cout << ans << '\n';
	}
}