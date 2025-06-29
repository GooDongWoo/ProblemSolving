#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, ans[10001];

int main() {
	fastio;
	cin >> N;
	int idx = N;
	int target = 0;
	while (idx > 0) {
		int logn = log2(idx);
		int target = pow(2, logn + 1);
		// (target - idx) ~ (idx)
		rep(i, target - idx, idx + 1) {
			ans[i] = target - i;
		}
		idx = target - idx - 1;
	}
	rep(i, 1, N + 1) {
		printf("%d\n", ans[i]);
	}
}