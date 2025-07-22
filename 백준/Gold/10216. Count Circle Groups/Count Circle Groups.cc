#define rep(i,a,b) for(int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

struct Node {
	int x, y, r;
	bool operator<(const Node& b) const {
		return tie(x, y, r) < tie(b.x, b.y, b.r);
	}
};
int T, N, p[3000], c[3000], cnter;
Node arr[3000];

void init() {
	cnter = N;
	rep(i, 0, N) {
		p[i] = i;
		c[i] = 1;
	}
}

int find_(int num) {
	if (p[num] != num) {
		p[num] = find_(p[num]);
	}
	return p[num];
}

void union_(int a, int b) {
	int pa, pb;
	pa = find_(a);
	pb = find_(b);
	if (pa == pb) {
		return;
	}
	if (c[pa] < c[pb]) {
		swap(pa, pb);
	}
	p[pb] = pa;
	c[pa] += c[pb];
	return;
}

bool chck(Node& a, Node& b) {
	if ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) <= (a.r + b.r) * (a.r + b.r)) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	rep(test_case, 1, T + 1) {
		cin >> N;
		init();
		rep(i, 0, N) {
			int a, b, c;
			cin >> a >> b >> c;
			arr[i] = { a,b,c };
		}
		rep(i, 0, N) {
			rep(j, i + 1, N) {
				if (chck(arr[i], arr[j])) {
					if (find_(i) != find_(j)) {
						cnter--;
						union_(i, j);
					}
				}
			}
		}
		cout << cnter << '\n';
	}

	return 0;
}