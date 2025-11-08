#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

struct Item {
	int y, x, k;
};
int N, M, K, mat[1000][1000], v[1000][1000][11];
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
queue<Item> q;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N >> M >> K;
	rep(i, 0, N) {
		string line;
		cin >> line;
		rep(j, 0, M) {
			mat[i][j] = line[j] - '0';
		}
	}
	q.push({ 0,0,0 });
	v[0][0][0] = 1;
	while (q.size()) {
		auto curp = q.front(); q.pop();
		int cy = curp.y, cx = curp.x, ck = curp.k;
		rep(i, 0, 4) {
			int ny = cy + dys[i];
			int nx = cx + dxs[i];
			if (!(0 <= ny && ny < N && 0 <= nx && nx < M)) {
				continue;
			}
			if (mat[ny][nx] == 0 && v[ny][nx][ck] == 0) {
				v[ny][nx][ck] = v[cy][cx][ck] + 1;
				q.push({ ny,nx,ck });
			}
			if (mat[ny][nx] == 1 && ck + 1 <= K && v[ny][nx][ck + 1] == 0) {
				v[ny][nx][ck + 1] = v[cy][cx][ck] + 1;
				q.push({ ny,nx,ck + 1 });
			}
		}
	}
	int ans = 1e9;
	rep(i, 0, K + 1) {
		ans = min(ans, ((v[N - 1][M - 1][i] == 0) ? (int)1e9 : v[N - 1][M - 1][i]));
	}
	cout << (ans == 1e9 ? -1 : ans);
	return 0;
}