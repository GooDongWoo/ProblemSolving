#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

LL x, y, w, s,ans;

int main() {
	fastio;
	cin >> x >> y >> w >> s;
	if (s < 2 * w) {
		LL tmp = min(x, y);
		x -= tmp;
		y -= tmp;
		ans += s * tmp;
	}
	if (s < w) {
		if (x > y) {
			ans += (x / 2) * (2 * s);
			if (x & 1) 
				x = 1;
			else 
				x = 0;
		}
		else {
			ans += (y / 2) * (2 * s);
			if (y & 1)
				y = 1;
			else
				y = 0;
		}
	}
	ans += x * w + y * w;
	printf("%lld\n", ans);
	return 0;
}