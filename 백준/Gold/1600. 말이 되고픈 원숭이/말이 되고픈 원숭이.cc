#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

struct Item {
	int y, x, k;
};
int K, W, H;
bool mat[200][200], v[200][200][30];
int dys[] = { 1,0,-1,0,2,1,-1,-2,-2,-1,1,2 };
int dxs[] = { 0,1,0,-1,1,2,2,1,-1,-2,-2,-1 };

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> K >> W >> H;
	rep(i, 0, H) {
		rep(j, 0, W) {
			cin >> mat[i][j];
		}
	}
	queue<Item> q;
	v[0][0][0] = true;
	q.push({ 0,0,0 });
	int timer = 0;
	while (q.size()) {
		int miniCycle = q.size();
		rep(tmp__, 0, miniCycle) {
			auto curp = q.front(); q.pop();
			int cy = curp.y, cx = curp.x, ck = curp.k;
			if (cy == H - 1 && cx == W - 1) {
				cout << timer;
				return 0;
			}
			rep(step, 0, 12) {
				int ny = cy + dys[step];
				int nx = cx + dxs[step];
				int nk = (step > 3) ? ck + 1 : ck;
				if (!(0 <= ny && ny < H && 0 <= nx && nx < W) || mat[ny][nx] || nk > K || v[ny][nx][nk]) {
					continue;
				}
				v[ny][nx][nk] = true;
				q.push({ ny,nx,nk });
			}
		}
		timer++;
	}
	cout << -1;
	return 0;
}
