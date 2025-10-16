#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int T, W, H, v[1000][1000], sy, sx;
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
char mat[1000][1000];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> T;
	rep(test_case, 0, T) {
		queue<pair<int, int>> q;
		cin >> W >> H;
		rep(i, 0, H) {
			rep(j, 0, W) {
				v[i][j] = 1e9;
				cin >> mat[i][j];
				if (mat[i][j] == '@') {
					sy = i; sx = j;
					mat[i][j] = '.';
				}
				else if (mat[i][j] == '*') {
					q.push({ i,j });
					v[i][j] = 0;
				}
			}
		}
		while (q.size()) {
			auto curp = q.front(); q.pop();
			int cy = curp.first, cx = curp.second;
			rep(step, 0, 4) {
				int ny = cy + dys[step];
				int nx = cx + dxs[step];
				if (!(0 <= ny && ny < H && 0 <= nx && nx < W) || mat[ny][nx] == '#' || (v[ny][nx] <= v[cy][cx] + 1)) {
					continue;
				}
				v[ny][nx] = v[cy][cx] + 1;
				q.push({ ny,nx });
			}
		}
		int ans = 1e9;
		q.push({ sy,sx });
		v[sy][sx] = 0;
		while (q.size() && ans == 1e9) {
			auto curp = q.front(); q.pop();
			int cy = curp.first, cx = curp.second;
			if (cy == H - 1 || cy == 0 || cx == W - 1 || cx == 0) {
				ans = min(ans, v[cy][cx] + 1);
			}
			rep(step, 0, 4) {
				int ny = cy + dys[step];
				int nx = cx + dxs[step];
				if (!(0 <= ny && ny < H && 0 <= nx && nx < W) || mat[ny][nx] == '#' || (v[ny][nx] <= (v[cy][cx] + 1))) {
					continue;
				}
				v[ny][nx] = v[cy][cx] + 1;
				q.push({ ny,nx });
			}
		}
		if (ans == 1e9) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			cout << ans << '\n';
		}
	}
	return 0;
}