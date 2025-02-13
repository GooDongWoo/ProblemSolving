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
	int val, idx;
	bool operator< (const Point& o) const {
		return val < o.val;
	}
};
typedef struct tple {
	int val,s,e;
	bool operator< (const tple& o) const {
		return val < o.val;
	}
};

int N, cost, p[100000], Rank[100000];
Point a[100000], b[100000], c[100000];

int find_(int num) {
	if (p[num] != num) p[num] = find_(p[num]);
	return p[num];
}

void union_(int a, int b) {
	int ap, bp;
	ap = find_(a);bp = find_(b);
	if (ap == bp) return;
	if (Rank[ap] < Rank[bp]) swap(ap, bp);
	Rank[ap] += Rank[bp];
	p[bp] = ap;
	return;
}

int main() {
	fastio;
	cin >> N;
	rep(i, 0, N) {
		p[i] = i;Rank[i] = 1;
	}
	rep(i, 0, N) {
		cin >> a[i].val >> b[i].val >> c[i].val;
		a[i].idx = i;b[i].idx = i;c[i].idx = i;
	}
	sort(a, a + N);sort(b, b + N);sort(c, c + N);
	priority_queue<tple> pq;
	rep(i, 1, N) {
		pq.push({ -abs(a[i].val - a[i - 1].val),a[i].idx,a[i - 1].idx });
		pq.push({ -abs(b[i].val - b[i - 1].val),b[i].idx,b[i - 1].idx });
		pq.push({ -abs(c[i].val - c[i - 1].val),c[i].idx,c[i - 1].idx });
	}
	int ccost,s,e;
	while (pq.size()) {
		ccost= pq.top().val;s = pq.top().s;e = pq.top().e;
		pq.pop();
		if (find_(s) == find_(e)) continue;
		cost += -ccost;
		union_(s, e);
	}

	printf("%d\n", cost);	
	return 0;
}