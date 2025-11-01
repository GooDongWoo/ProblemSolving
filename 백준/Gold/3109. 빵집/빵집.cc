#include <iostream>
#include <algorithm>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int R, C, ans;
char mat[10000][500];
bool v[10000][500];
int drs[] = { 1,0,-1 };
int dcs[] = { 1,1,1 };

bool dfs(int r, int c) {
	v[r][c] = true;
	if (c == C - 1) {
		ans++;
		return true;
	}
	rep(step, 0, 3) {
		int nr = r + drs[step];
		int nc = c + dcs[step];
		if (!(0 <= nr && nr < R && 0 <= nc && nc < C) || mat[nr][nc] == 'x' || v[nr][nc]) {
			continue;
		}
		if (dfs(nr, nc)) {
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> R >> C;
	rep(i, 0, R) {
		rep(j, 0, C) {
			cin >> mat[i][j];
		}
	}
	rep(i, 0, R) {
		dfs(R - 1 - i, 0);
	}
	cout << ans;

	return 0;
}