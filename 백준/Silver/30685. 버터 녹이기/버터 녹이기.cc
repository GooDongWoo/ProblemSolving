#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

struct Item {
	LL x, h;
	bool operator <(const Item& b) const {
		return x < b.x;
	}
};
int N;
Item arr[300000];


bool chck(LL time) {
	LL bef = -9e18;
	rep(i, 0, N) {
		LL diff = min(time, (arr[i].h - 1) / 2);
		if (arr[i].x - diff <= bef) {
			return false;
		}
		bef = arr[i].x + diff;
	}
	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	rep(i, 0, N) {
		cin >> arr[i].x >> arr[i].h;
	}
	sort(arr, arr + N);

	// impossible?
	if (chck(9e18)) {
		cout << "forever\n";
		return 0;
	}
	// parametric search
	LL start, end, mid;
	start = 0;
	end = 1e9;
	while (start <= end) {
		mid = (start + end) / 2;
		if (chck(mid)) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << end;
	return 0;
}