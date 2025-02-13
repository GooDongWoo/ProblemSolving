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

typedef struct bug {
	int y, x, cnt, drc;
	bool live;
};
int T, N, M, K, ans, v[100][100], midx[100][100], tot[100][100];
int dys[] = { 1,0,-1,0 };// down, right, up, left;
int dxs[] = { 0,1,0,-1 };// down, right, up, left;
bug bgs[1000];

int main() {
	fastio;
	cout.tie(nullptr);
	cin >> T;
	rep(TC, 1, T + 1) {
		ans = 0;
		cin >> N >> M >> K;
		rep(i, 0, K) {
			cin >> bgs[i].y >> bgs[i].x >> bgs[i].cnt >> bgs[i].drc;
			bgs[i].live = 1;
			if (bgs[i].drc == 1)bgs[i].drc = 2;
			else if (bgs[i].drc == 2)bgs[i].drc = 0;
			else if (bgs[i].drc == 3)bgs[i].drc = 3;
			else bgs[i].drc = 1;
		}
		rep(time, 0, M) {
			memset(v, 0, sizeof(v)); memset(tot, 0, sizeof(tot));
			// move
			rep(i, 0, K) {
				if (bgs[i].live == false) continue;
				int y, x, ny, nx, drc;
				y = bgs[i].y; x = bgs[i].x;
				drc = bgs[i].drc;
				ny = y + dys[drc]; nx = x + dxs[drc];
				bgs[i].y = ny; bgs[i].x = nx;
				if (ny == 0 || ny == N - 1 || nx == 0 || nx == N - 1) {// side chck & drc reverse
					bgs[i].drc = (drc + 2) % 4;
					bgs[i].cnt /= 2;
					if (bgs[i].cnt == 0) bgs[i].live = false;
				}
				else {												// normal place;
					if (v[ny][nx] == 0) {
						v[ny][nx] = 1;
						tot[ny][nx] += bgs[i].cnt;
						midx[ny][nx] = i;
					}
					else {
						v[ny][nx] += 1;
						tot[ny][nx] += bgs[i].cnt;
						int bef = midx[ny][nx];
						if (bgs[bef].cnt < bgs[i].cnt) {
							bgs[bef].live = 0; midx[ny][nx] = i;
						}
						else bgs[i].live = 0;
					}
				}
			}
			rep(i, 0, N)rep(j, 0, N) if (v[i][j] > 1) bgs[midx[i][j]].cnt = tot[i][j];
		}
		rep(i, 0, K) if (bgs[i].live) ans += bgs[i].cnt;
		cout << '#' << TC << ' ' << ans << '\n';
	}
	return 0;
}