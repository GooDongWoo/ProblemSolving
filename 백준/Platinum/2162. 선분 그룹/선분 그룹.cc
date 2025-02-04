#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

typedef struct Point {
	int x, y;
};
typedef struct Line {
	Point a, b;
};

int n, p[3000], rnk[3000], cnters[3000], ans1, ans2;
Line ls[3000];

int find__(int a) {
	if (a != p[a]) p[a] = find__(p[a]);
	return p[a];
}
void union__(int a, int b) {
	int ap, bp;
	ap = find__(a);bp = find__(b);
	if (rnk[ap] < rnk[bp]) swap(ap, bp);
	rnk[ap] += rnk[bp]; rnk[bp] = 1;
	p[bp] = ap;
	return;
}
int ccw(Point p1, Point p2, Point p3) {
	int a, b, c, d, tmp;
	a = (p2.x - p1.x); b = (p2.y - p1.y);
	c = (p3.x - p2.x); d = (p3.y - p2.y);
	tmp = (a * d) - (b * c);
	if (tmp) return tmp / abs(tmp);
	else return tmp;
}

int innerdot(Point p1, Point p2, Point p3) {
	int a, b, c, d;
	a = (p2.x - p1.x); b = (p2.y - p1.y);
	c = (p3.x - p1.x); d = (p3.y - p1.y);
	return a * c + b * d;
}

bool crosschck(Line a, Line b) {
	int tmp1, tmp2;
	tmp1 = ccw(a.a, a.b, b.a) * ccw(a.a, a.b, b.b);
	tmp2 = ccw(b.a, b.b, a.a) * ccw(b.a, b.b, a.b);
	if (tmp1 == 0 && tmp2 == 0) {
		return innerdot(a.a, b.a, b.b) <= 0 || innerdot(a.b, b.a, b.b) <= 0
			|| innerdot(b.a, a.a, a.b) <= 0 || innerdot(b.b, a.a, a.b) <= 0;
	}
	return (tmp1 <= 0) && (tmp2 <= 0);
}

int main() {
	fastio;
	cin >> n;
	rep(i, 0, n) p[i] = i;
	fill(rnk, rnk + n, 1);
	rep(i, 0, n) cin >> ls[i].a.x >> ls[i].a.y >> ls[i].b.x >> ls[i].b.y;
	rep(i, 1, n) {
		rep(j, 0, i) {
			if (crosschck(ls[i], ls[j])) union__(i, j);
		}
	}
	rep(i, 0, n) find__(i);
	rep(i, 0, n) cnters[p[i]]++;
	rep(i, 0, n) if (cnters[i]) ans1++;
	ans2 = *max_element(cnters, cnters+n);
	printf("%d\n%d", ans1, ans2);
	return 0;
}