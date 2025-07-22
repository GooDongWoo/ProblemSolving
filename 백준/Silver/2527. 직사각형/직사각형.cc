#define rep(i,a,b) for(int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

struct rect {
	int x1, y1, x2, y2;
	bool operator< (const rect& b) const {
		return tie(x1, y1) < tie(b.x1, b.y1);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int a, b, c, d;
	rect r[2];
	rep(test_case, 0, 4) {
		rep(i, 0, 2) {
			cin >> a >> b >> c >> d;
			r[i] = { a,b,c,d };
		}
		sort(r, r + 2);
		if ((r[1].x1 > r[0].x2) || (r[1].y2 < r[0].y1) || (r[1].y1 > r[0].y2)) {// 안겹침;;
			cout << "d\n";
		}
		else if ((r[0].x2 == r[1].x1 && r[0].y1 == r[1].y2) || (r[0].x2 == r[1].x1 && r[0].y2 == r[1].y1)) {// 점 교차
			cout << "c\n";
		}
		else if ((r[0].x2 > r[1].x1 && r[0].y1 == r[1].y2) || (r[0].x2 > r[1].x1 && r[0].y2 == r[1].y1)
			|| (r[0].x2 == r[1].x1)) {// 선 교차
			cout << "b\n";
		}
		else {// 사각 교차
			cout << "a\n";
		}
	}
	return 0;
}