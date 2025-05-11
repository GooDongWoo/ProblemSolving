#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int N, a, b, ans;

int main() {
	fastio;
	cin >> N;
	ans = 1e9;
	rep(i, 0, N) {
		cin >> a >> b;
		if (a <= b) {
			ans = min(ans, b);
		}
	}
	if (ans == 1e9)
		printf("-1");
	else
		printf("%d\n", ans);

	return 0;
}