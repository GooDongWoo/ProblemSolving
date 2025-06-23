#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
using namespace std;

int G;
set<LL> ans;

int main() {
	fastio;
	cin >> G;
	int LIMIT = (G + 1) / 2;
	for (LL aft = 2; aft < LIMIT + 1; ++aft) {
		LL bef_s = aft * aft - G;
		if (bef_s <= 0) {
			continue;
		}
		LL candidate = sqrt(bef_s);
		if ((bef_s == candidate * candidate)) {
			ans.insert(aft);
		}
	}
	if (ans.size()) {
		for (const auto& x : ans) {
			printf("%lld\n", x);
		}
	}
	else {
		printf("-1\n");
	}
}