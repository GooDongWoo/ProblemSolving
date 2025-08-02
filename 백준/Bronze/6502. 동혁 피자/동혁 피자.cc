#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	double r, w, l;
	int cnt = 1;
	while (cin >> r && r != 0) {
		cin >> w >> l;
		if (sqrt(w*w + l*l) <= 2*r) {
			cout << "Pizza " << cnt << " fits on the table.\n";
		} else {
			cout << "Pizza " << cnt << " does not fit on the table.\n";
		}
		cnt++;
	}
	return 0;
}