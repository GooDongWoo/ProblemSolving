#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

struct Item {
	int l, r, c;
};
int L, R, C, v[30][30][30], sdir[3], edir[3];
char mat[30][30][30];
int dls[] = { 1,-1,0,0,0,0 };
int drs[] = { 0,0,1,-1,0,0 };
int dcs[] = { 0,0,0,0,1,-1 };


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	while (true) {
		memset(v, 0, sizeof(v));
		cin >> L >> R >> C;
		if (L * R * C == 0) {
			break;
		}
		rep(i, 0, L) {
			rep(j, 0, R) {
				rep(k, 0, C) {
					cin >> mat[i][j][k];
					if (mat[i][j][k] == 'S') {
						sdir[0] = i;
						sdir[1] = j;
						sdir[2] = k;
					}
					else if (mat[i][j][k] == 'E') {
						edir[0] = i;
						edir[1] = j;
						edir[2] = k;
					}
				}
			}
		}
		queue<Item> q;
		v[sdir[0]][sdir[1]][sdir[2]] = 1;
		q.push({ sdir[0] ,sdir[1],sdir[2] });
		while (q.size()) {
			auto curp = q.front(); q.pop();
			int cl = curp.l, cr = curp.r, cc = curp.c;
			rep(step, 0, 6) {
				int nl = cl + dls[step];
				int nr = cr + drs[step];
				int nc = cc + dcs[step];
				if (!(0 <= nl && nl < L && 0 <= nr && nr < R && 0 <= nc && nc < C) || mat[nl][nr][nc] =='#' || v[nl][nr][nc]) {
					continue;
				}
				v[nl][nr][nc] = v[cl][cr][cc] + 1;
				q.push({ nl,nr,nc });
			}
		}
		if (v[edir[0]][edir[1]][edir[2]]) {
			cout << "Escaped in "<< v[edir[0]][edir[1]][edir[2]] -1<<" minute(s).\n";
		}
		else {
			cout << "Trapped!\n";
		}
	}
	return 0;
}