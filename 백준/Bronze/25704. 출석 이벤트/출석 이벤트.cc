#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;


int N, P, ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> P;
	ans = P;
	if (N >= 5) {
		ans = min(ans, max(0, P - 500));
	}
	if (N >= 10) {
		ans = min(ans, (int)(P * .9));
	}
	if (N >= 15) {
		ans = min(ans, max(0, P - 2000));
	}
	if (N >= 20) {
		ans = min(ans, (int)(P * .75));
	}
	cout << ans;
	return 0;
}