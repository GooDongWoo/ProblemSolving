#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

const int MAX = 65538;
int N, K, bit[MAX];
queue<int> q;
LL ans;

void update(int idx, int val) {
	while (idx < MAX) {
		bit[idx] += val;
		idx += idx & -idx;
	}
	return;
}

LL query(int idx) {
	LL ret = 0;
	while (idx > 0) {
		ret += bit[idx];
		idx -= idx & -idx;
	}
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	rep(i, 0, K - 1) {
		int a;
		cin >> a; a++;
		q.push(a);
		update(a, 1);
	}
	rep(i, 0, N - K + 1) {
		int a;
		cin >> a; a++;
		q.push(a);
		update(a, 1);
		int start = 1, end = 65537;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (query(mid) < (K + 1) / 2) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		ans += start - 1;
		int pop1 = q.front(); q.pop();
		update(pop1, -1);
	}
	cout << ans;
	return 0;
}