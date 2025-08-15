#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N,M,bef,ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N>>M;
	rep(i, 0, N) {
		int a;
		cin >> a;
		bef += a;
		bef = max(0, bef);
		if (bef >= M) {
			ans++;
		}
	}
	cout << ans;

	return 0;
}