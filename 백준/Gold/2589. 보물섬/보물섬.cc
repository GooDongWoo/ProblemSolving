#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int R, C, v[50][50], ans;
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
bool mat[50][50];

void Run(int r, int c) {
	memset(v, 0, sizeof(v));
	queue<pair<int, int>> q;
	v[r][c] = 1;
	q.push({ r,c });
	while (q.size()) {
		auto curp = q.front(); q.pop();
		int cy = curp.first, cx = curp.second;
		rep(step, 0, 4) {
			int ny = cy + dys[step];
			int nx = cx + dxs[step];
			if (!(0 <= ny && ny < R && 0 <= nx && nx < C) || !mat[ny][nx] || v[ny][nx]) {
				continue;
			}
			q.push({ ny,nx });
			v[ny][nx] = v[cy][cx] + 1;
			ans = max(ans, v[cy][cx]);
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> R >> C;
	rep(i, 0, R) {
		rep(j, 0, C) {
			char tmp;
			cin >> tmp;
			if (tmp == 'L') {
				mat[i][j] = true;
			}
		}
	}
	rep(i, 0, R) {
		rep(j, 0, C) {
			if (!mat[i][j]) {
				continue;
			}
			Run(i, j);
		}
	}
	cout << ans;
	return 0;
}
