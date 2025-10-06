#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int R, C, goseum[2], beaver[2], v[50][50];
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
char mat[50][50];
queue<pair<int, int>> q;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> R >> C;
	rep(i, 0, R) {
		rep(j, 0, C) {
			v[i][j] = 1e9;
			cin >> mat[i][j];
			if (mat[i][j] == 'D') {
				beaver[0] = i;
				beaver[1] = j;
			}
			if (mat[i][j] == 'S') {
				goseum[0] = i;
				goseum[1] = j;
				mat[i][j] = '.';
			}
			if (mat[i][j] == '*') {
				q.push({ i,j });
				v[i][j] = 0;
			}
		}
	}
	while (q.size()) {
		auto curp = q.front(); q.pop();
		int cy = curp.first, cx = curp.second;
		rep(i, 0, 4) {
			int ny = cy + dys[i]; int nx = cx + dxs[i];
			if (!(0 <= ny && ny < R && 0 <= nx && nx < C) || mat[ny][nx] == 'D' || mat[ny][nx] == 'X') {
				continue;
			}
			if (v[ny][nx] > v[cy][cx] + 1) {
				v[ny][nx] = v[cy][cx] + 1;
				q.push({ ny,nx });
			}
		}
	}
	q.push({ goseum[0], goseum[1] });
	v[goseum[0]][goseum[1]] = 0;
	while (q.size()) {
		auto curp = q.front(); q.pop();
		int cy = curp.first, cx = curp.second;
		rep(i, 0, 4) {
			int ny = cy + dys[i]; int nx = cx + dxs[i];
			if (!(0 <= ny && ny < R && 0 <= nx && nx < C) || mat[ny][nx] == 'X') {
				continue;
			}
			if (v[ny][nx] > v[cy][cx] + 1) {
				v[ny][nx] = v[cy][cx] + 1;
				q.push({ ny,nx });
			}
		}
	}
	if (v[beaver[0]][beaver[1]] == 1e9) {
		cout << "KAKTUS";
	}
	else {
		cout << v[beaver[0]][beaver[1]];
	}
	return 0;
}