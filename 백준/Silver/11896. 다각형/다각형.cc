#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

LL a, b,ans;

int main() {
	fastio;
	cin >> a >> b;
	if (a <= 2 && b >= 2) {
		a = 4;
	}
	if (a > b) {
		b = 3;
	}
	a--;
	a /= 2;
	b /= 2;
	printf("%lld\n", b*(b+1) - a*(a+1));
}