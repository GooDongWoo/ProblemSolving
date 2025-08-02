#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	double x, y;
	while (cin >> x >> y && (x != 0 || y != 0)) {
		if (x == 0 || y == 0) {
			cout << "AXIS" << endl;
		} else if (x > 0 && y > 0) {
			cout << "Q1" << endl;
		} else if (x < 0 && y > 0) {
			cout << "Q2" << endl;
		} else if (x < 0 && y < 0) {
			cout << "Q3" << endl;
		} else {
			cout << "Q4" << endl;
		}
	}
    cout << "AXIS" << endl;
	return 0;
}