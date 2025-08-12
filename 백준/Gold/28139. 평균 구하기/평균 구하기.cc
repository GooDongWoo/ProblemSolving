#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, arr[5000][2];
double ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	rep(i, 0, N) {
		cin >> arr[i][0] >> arr[i][1];
	}
	rep(i, 0, N - 1) {
		rep(j, i + 1, N) {
			ans += 2 * sqrt((((arr[i][0] - arr[j][0]) * (arr[i][0] - arr[j][0])) + ((arr[i][1] - arr[j][1]) * (arr[i][1] - arr[j][1]))));
		}
	}
	cout << fixed << setprecision(10) << ans / N;

	return 0;
}