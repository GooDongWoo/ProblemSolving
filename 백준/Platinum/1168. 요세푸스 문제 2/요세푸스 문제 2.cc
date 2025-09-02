#include <iostream>
#include <algorithm>
#include <string>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;
using namespace std;

int N, K, bit[100001];

void build(int idx) {

}

void update(int idx, int val) {
	while (idx <= N) {
		bit[idx] += val;
		idx += idx & -idx;
	}
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
	cin >> N >> K;
	rep(i, 1, N + 1) {
		update(i, 1);
	}
	int bef = 0;
	string ans = "<";
	rep(step, 0, N) {
		int start = 1, end = N, target = (bef + K - 1) % (N - step) + 1;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (query(mid) < target) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		ans += to_string(start) + ", ";
		update(start, -1);
		bef = (target - 1);
	}
	ans.pop_back();
	ans.pop_back();
	ans += '>';
	cout << ans;
	return 0;
}