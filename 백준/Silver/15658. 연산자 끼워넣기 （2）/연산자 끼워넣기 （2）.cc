#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, arr[11], optrs[4], maxV = -1e9, minV = 1e9, ans;

void bt(int idx) {
	if (idx == N) {
		maxV = max(maxV, ans);
		minV = min(minV, ans);
		return;
	}
	else {
		rep(i, 0, 4) {
			if (optrs[i] > 0) {
				--optrs[i];
				int bef = ans;
				if (i == 0) {
					ans += arr[idx];
				}
				else if (i == 1) {
					ans -= arr[idx];
				}
				else if (i == 2) {
					ans *= arr[idx];
				}
				else {
					ans /= arr[idx];
				}
				bt(idx + 1);
				++optrs[i];
				ans = bef;
			}
		}
	}
}
int main() {
	fastio;
	cin >> N;
	rep(i, 0, N) {
		cin >> arr[i];
	}
	rep(i, 0, 4) {
		cin >> optrs[i];
	}
	ans = arr[0];
	bt(1);
	printf("%d\n%d", maxV, minV);
}