#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

const int MAX = 30000;
class Item {
public:
	int x, y1, y2, isStart;
	bool operator<(const Item& b)const {
		if (x != b.x) {
			return x < b.x;
		}
		else {
			return isStart < b.isStart;
		}
	}
};
int N;
int cnt[4 * (MAX + 1)], segtree[4 * (MAX + 1)];
Item arr[2 * MAX];
LL ans;

void update(int idx, int l, int r, int ql, int qr, int val) {
	if (qr < l || r < ql) {
		return;
	}
	if (ql <= l && r <= qr) {
		cnt[idx] += val;
	}
	else {
		int mid = (l + r) / 2;
		update(2 * idx, l, mid, ql, qr, val);
		update(2 * idx + 1, mid + 1, r, ql, qr, val);
	}
	if (cnt[idx]) {
		segtree[idx] = r - l + 1;
	}
	else {
		if (l == r) {
			segtree[idx] = 0;
		}
		else {
			segtree[idx] = segtree[2 * idx] + segtree[2 * idx + 1];
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 0, N) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		y1++;
		arr[2 * i].x = x1;
		arr[2 * i].y1 = y1;
		arr[2 * i].y2 = y2;
		arr[2 * i].isStart = 1;

		arr[2 * i + 1].x = x2;
		arr[2 * i + 1].y1 = y1;
		arr[2 * i + 1].y2 = y2;
		arr[2 * i + 1].isStart = -1;
	}
	sort(arr, arr + (2 * N));
	int bef = arr[0].x;
	rep(i, 0, 2 * N) {
		ans += (arr[i].x - bef) * ((LL)segtree[1]);
		update(1, 1, 30000, arr[i].y1, arr[i].y2, arr[i].isStart);
		bef = arr[i].x;
	}
	cout << ans;
	return 0;
}
