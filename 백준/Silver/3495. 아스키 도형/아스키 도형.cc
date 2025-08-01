#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int H, W, ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> H >> W;
	rep(i, 0, H) {
		vector<int> cl;
		rep(j, 0, W) {
			char a;
			cin >> a;
			if (a == '/' || a == '\\') {
				cl.push_back(j);
			}
		}
		for (int i = 0; i < cl.size(); i += 2) {
			ans += cl[i + 1] - cl[i];
		}
	}
	cout << ans;
	return 0;
}