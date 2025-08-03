#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

struct Point {
	LL x, y;
};
Point ps[4];

pair<LL, LL> makeVector(Point a, Point b) {
	return{ b.x - a.x,b.y - a.y };
}
LL dotProduct(pair<LL, LL> a, pair<LL, LL> b) {
	return a.first * b.first + a.second * b.second;
}
LL ccw(Point a, Point b, Point c) {
	pair<LL, LL> p1 = makeVector(a, b);
	pair<LL, LL> p2 = makeVector(a, c);
	LL t1, t2;
	t1 = p1.first * p2.second;
	t2 = p1.second * p2.first;
	return (t1 > t2) - (t2 > t1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	rep(i, 0, 4) {
		cin >> ps[i].x >> ps[i].y;
	}
	LL c1, c2, c3, c4;
	c1 = ccw(ps[0], ps[1], ps[2]);
	c2 = ccw(ps[0], ps[1], ps[3]);
	c3 = ccw(ps[2], ps[3], ps[0]);
	c4 = ccw(ps[2], ps[3], ps[1]);
	if ((c1 || c2 || c3 || c4) == 0) {//일직선
		if (dotProduct(makeVector(ps[0], ps[2]), makeVector(ps[0], ps[3])) <= 0 || dotProduct(makeVector(ps[1], ps[2]), makeVector(ps[1], ps[3])) <= 0 ||
			dotProduct(makeVector(ps[2], ps[0]), makeVector(ps[2], ps[1])) <= 0 || dotProduct(makeVector(ps[3], ps[0]), makeVector(ps[3], ps[1])) <= 0) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}
	else if (((c1 * c2) <= 0) && ((c3 * c4) <= 0)) {
		cout << 1 << '\n';
	}
	else {
		cout << 0 << '\n';
	}
	return 0;
}