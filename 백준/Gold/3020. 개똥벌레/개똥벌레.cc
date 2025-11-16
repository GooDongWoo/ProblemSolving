#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

#define rep(i, a, b) for (int i=a;i<b;++i)
using LL = long long;
using namespace std;

int N, H, arr1[100000], arr2[100000], ans, anscnt;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N >> H;
	rep(i, 0, N / 2) {
		cin >> arr1[i] >> arr2[i];
		arr2[i] = H - arr2[i];
	}
	sort(arr1, arr1 + (N / 2));
	sort(arr2, arr2 + (N / 2));
	ans = 1e9;
	rep(i, 1, H + 1) {
		int minicnter = 0;
		minicnter += N/2-(upper_bound(arr1, arr1 + (N / 2), i) - arr1);
		minicnter += upper_bound(arr2, arr2 + (N / 2), i) - arr2;
		if (ans == minicnter) {
			anscnt++;
		}
		else if (ans > minicnter) {
			anscnt = 1;
			ans = minicnter;
		}
		else {
		}
	}
	cout << ans << ' ' << anscnt;
	return 0;
}