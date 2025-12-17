#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <cstring>
#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

const double PI = acos(-1);
struct Circle {
	double x, y, r;
	bool operator<(const Circle& b)const {
		return r < b.r;
	}
};
Circle a, b;
double ans;

template<typename T>
T sqr(T a) {
	return a * a;
}
double bucheaArea(double r, double theta) {
	return sqr(r) * theta / 2.0;
}
double triangle(double r, double theta) {
	return sqr(r) * sin(theta) / 2.0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> a.x >> a.y >> a.r >> b.x >> b.y >> b.r;
	if (a < b) {
		swap(a, b);
	}
	double rsum = (a.r + b.r);
	double xdiff = (a.x - b.x);
	double ydiff = (a.y - b.y);
	double sqrdist = sqr(xdiff) + sqr(ydiff);
	double dist = sqrt(sqrdist);
	double ans = 0;
	if ((sqr(rsum) <= sqrdist)) {
		ans = 0;
	}
	else if (a.r >= sqrt(sqrdist) + b.r) {
		ans = sqr(b.r) * PI;
	}
	else {
		double A = acos((-sqr(b.r) + sqr(a.r) + sqrdist) / (2 * a.r * dist)) * 2;
		double B = acos((-sqr(a.r) + sqr(b.r) + sqrdist) / (2 * b.r * dist)) * 2;
		ans = bucheaArea(a.r, A) + bucheaArea(b.r, B) - triangle(a.r, A) - triangle(b.r, B);
	}

	printf("%.3lf", ((double)((int)round(ans * 1000))) / 1000.);
	return 0;
}