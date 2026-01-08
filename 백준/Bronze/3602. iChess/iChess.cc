#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;

int B, W, ans;

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cout.tie(NULL);
	cin >> B >> W;
	
	if (B < W)swap(B, W);
	rep(i, 0, 100) {
		int N = 2 * (i * i);
		int T = N + 2 * i;
		if (T + 1 <= B && T <= W) {
			ans = max(ans, 2 * i + 1);
		}
		if (N <= B && N <= W) {
			ans = max(ans, 2 * i);
		}
	}
	if (ans == 0) {
		cout << "Impossible";
		return 0;
	}
	cout << ans;
	return 0;
}