#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;

struct Item {
	int y, x, ks;
};
int N, M, v[50][50][64], sy, sx;
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
char mat[50][50];

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cout.tie(NULL);
	cin >> N >> M;
	rep(i, 0, N) {
		rep(j, 0, M) {
			cin >> mat[i][j];
			if (mat[i][j] == '0') {
				mat[i][j] = '.';
				sy = i; sx = j;
			}
		}
	}

	queue<Item> q;
	q.push({ sy,sx,0 });
	v[sy][sx][0] = 1;
	while (q.size()) {
		auto curp = q.front(); q.pop();
		int cy = curp.y, cx = curp.x, cks = curp.ks;
		rep(step, 0, 4) {
			int ny = cy + dys[step];
			int nx = cx + dxs[step];
			int nks = cks;
			if (!(0 <= ny && ny < N && 0 <= nx && nx < M) || mat[ny][nx] == '#') {
				continue;
			}

			int shiftVal1 = mat[ny][nx] - 'a';
			int shiftVal2 = mat[ny][nx] - 'A';
			if (0 <= shiftVal1 && shiftVal1 < 6) {
				nks |= (1 << shiftVal1);
			}
			else if (0 <= shiftVal2 && shiftVal2 < 6) {
				if ((cks & (1 << shiftVal2)) == 0) {
					continue;
				}
			}
			else {}

			if (v[ny][nx][nks] > 0) {
				continue;
			}
			v[ny][nx][nks] = v[cy][cx][cks] + 1;
			q.push({ ny,nx,nks });
			if (mat[ny][nx] == '1') {
				cout << v[ny][nx][cks] - 1;
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}