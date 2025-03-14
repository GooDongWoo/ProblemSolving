#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

LL N, arr[100][2], mLoss, mb, ma, Loss, y, x, k, b;

int main() {
	fastio;
	cin >> N;
	rep(i, 0, N) cin >> arr[i][0] >> arr[i][1];
	mLoss = 1e18;
	rep(a, 1, 101) {
		rep(b, 1, 101) {
			Loss = 0;
			rep(i, 0, N) {
				LL tmp = arr[i][1] - (a * arr[i][0] + b);
				Loss += tmp * tmp;
			}
			if (Loss < mLoss) {
				mLoss = Loss;
				ma = a; mb = b;
			}
		}
	}
	printf("%lld %lld", ma, mb);
}