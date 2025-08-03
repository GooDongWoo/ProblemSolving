#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

struct Point {
	LL x, y;
	Point() {}
	Point(LL x, LL y) : x(x), y(y) {}
	bool operator<(const Point b) const {
		if (x != b.x) {
			return x < b.x;
		}
		else {
			return y < b.y;
		}
	}
};
Point ps[4];

pair<LL, LL> makeVector(Point a, Point b) {
	return{ b.x - a.x, b.y - a.y };
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

LL crossProduct(Point a, Point b, Point c) {
	pair<LL, LL> p1 = makeVector(a, b);
	pair<LL, LL> p2 = makeVector(a, c);
	return p1.first * p2.second - p1.second * p2.first;
}

pair<double, double> getIntersection(Point p1, Point p2, Point p3, Point p4) {
	LL s1 = crossProduct(p1, p2, p3);
	LL s2 = crossProduct(p1, p2, p4);
	double ratio = (double)s1 / (s1 - s2);
	pair<LL, LL> vec = makeVector(p3, p4);
	double px = p3.x + ratio * vec.first;
	double py = p3.y + ratio * vec.second;
	return { px, py };
}

bool isOnly(Point p1, Point p2, Point p3, Point p4, pair<double, double>& intersection) {
	if (p2.x == p3.x && p2.y == p3.y) {
		intersection = { (double)p2.x, (double)p2.y };
		return true;
	}
	if (p1.x == p4.x && p1.y == p4.y) {
		intersection = { (double)p1.x, (double)p1.y };
		return true;
	}
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	rep(i, 0, 4) {
		cin >> ps[i].x >> ps[i].y;
	}
	sort(ps, ps + 2);
	sort(ps + 2, ps + 4);
	LL c1, c2, c3, c4;
	c1 = ccw(ps[0], ps[1], ps[2]);
	c2 = ccw(ps[0], ps[1], ps[3]);
	c3 = ccw(ps[2], ps[3], ps[0]);
	c4 = ccw(ps[2], ps[3], ps[1]);

	bool intersects = false;
	bool hasUniquePoint = false;
	pair<double, double> intersection;

	if ((c1 || c2 || c3 || c4) == 0) { // 일직선
		if (dotProduct(makeVector(ps[0], ps[2]), makeVector(ps[0], ps[3])) <= 0 ||
			dotProduct(makeVector(ps[1], ps[2]), makeVector(ps[1], ps[3])) <= 0 ||
			dotProduct(makeVector(ps[2], ps[0]), makeVector(ps[2], ps[1])) <= 0 ||
			dotProduct(makeVector(ps[3], ps[0]), makeVector(ps[3], ps[1])) <= 0) {
			intersects = true;

			hasUniquePoint = isOnly(ps[0], ps[1], ps[2], ps[3], intersection);
		}
	}
	else if (((c1 * c2) <= 0) && ((c3 * c4) <= 0)) {
		intersects = true;
		hasUniquePoint = true;
		intersection = getIntersection(ps[0], ps[1], ps[2], ps[3]);
	}

	if (intersects) {
		cout << 1 << '\n';
		if (hasUniquePoint) {
			cout << fixed << setprecision(16) << intersection.first << " " << intersection.second << '\n';
		}
	}
	else {
		cout << 0 << '\n';
	}

	return 0;
}