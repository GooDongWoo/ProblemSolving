#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

LL X, M, ans;

int main() {
	fastio;
	cin >> X >> M;
	ans = X;
	rep(i, 1, M + 1) {
		ans += X;
	}
	printf("%lld\n", ans);
}