#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

LL N, arr[100000], ans, psum;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	rep(i, 0, N) {
		cin >> arr[i];
	}
	ans = arr[0];
	psum = arr[0];
	rep(i, 1, N) {
		ans = max(ans,arr[i] - psum);
		psum += arr[i];
	}
	cout << ans;
	return 0;
}