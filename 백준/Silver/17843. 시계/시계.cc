#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

int T;
double h, m, s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> h >> m >> s;
		double deg[3];
		deg[2] = (s * 6);
		deg[1] = (m * 6) + 6 * (deg[2] / 360);
		deg[0] = (h * 30) + 30 * (deg[1] / 360);
		sort(deg, deg + 3);
		cout << fixed<< setprecision(6) <<min((deg[1] - deg[0]), min((deg[2] - deg[1]), (deg[0] - deg[2] + 360)))<<'\n';
	}

	return 0;
}