#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int N, M, p[200], c[200], cnum, targetP;
bool Flag = 1;

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

void init() {
	rep(i, 0, N) {
		p[i] = i;
		c[i] = 1;
	}
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> N >> M;
	init();
	rep(i, 0, N) {
		rep(j, 0, N) {
			int isConnect;
			cin >> isConnect;
			if (i == j) {
				continue;
			}
			if (isConnect) {
				union_(i, j);
			}
		}
	}
	cin >> cnum; cnum--;
	targetP = find_(cnum);
	rep(i, 1, M) {
		cin >> cnum; cnum--;
		int tmp = find_(cnum);
		if (tmp != targetP) {
			Flag = 0;
			break;
		}
	}
	if (Flag) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}