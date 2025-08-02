#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

double a, b, c;

double calc(double z) {
	z = z * z;
	return sqrt((a - z) * (b - z)) / (sqrt(b - z) + sqrt(a - z));
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> b >> c;
	a = a * a;
	b = b * b;
	double start = 0, end = min(a, b);
	while (end-start > 1e-5) {
		double mid = mid = (start + end) / 2;
		if (c < calc(mid)) {
			start = mid;
		}
		else {
			end = mid;
		}
	}
	cout << start;
	return 0;
}