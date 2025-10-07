#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int R, C, js[2], v[1000][1000];
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
bool IsWall[1000][1000];
queue<pair<int, int>> q;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> R >> C;
	rep(i, 0, R) {
		rep(j, 0, C) {
			v[i][j] = 1e9;
			char tmp;
			cin >> tmp;
			if (tmp == '#') {
				IsWall[i][j] = true;
			}
			else if (tmp == 'F') {
				q.push({ i,j });
				v[i][j] = 0;
			}
			else if (tmp == 'J') {
				js[0] = i;
				js[1] = j;
			}
			else {
			}
		}
	}
	while (q.size()) {
		auto curp = q.front(); q.pop();
		int cy = curp.first, cx = curp.second;
		rep(step, 0, 4) {
			int ny = cy + dys[step];
			int nx = cx + dxs[step];
			if (!(0 <= ny && ny < R && 0 <= nx && nx < C) || IsWall[ny][nx] || (v[ny][nx] <= v[cy][cx] + 1)) {
				continue;
			}
			v[ny][nx] = v[cy][cx] + 1;
			q.push({ ny,nx });
		}
	}

	int sy = js[0];
	int sx = js[1];
	v[sy][sx] = 0;
	q.push({ sy,sx });
	while (q.size()) {
		auto curp = q.front(); q.pop();
		int cy = curp.first, cx = curp.second;
		if (cy == 0 || cy == R - 1 || cx == 0 || cx == C - 1) {
			cout << v[cy][cx] + 1 << '\n';
			return 0;
		}
		rep(step, 0, 4) {
			int ny = cy + dys[step];
			int nx = cx + dxs[step];
			if (!(0 <= ny && ny < R && 0 <= nx && nx < C) || IsWall[ny][nx] || (v[ny][nx] <= v[cy][cx] + 1)) {
				continue;
			}
			v[ny][nx] = v[cy][cx] + 1;
			q.push({ ny,nx });
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
