#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, M, R, mat[300][300];
bool v[300][300], v2[300][300];
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };

void rotate(int sy) {
	vector<int> arr;
	int cy = sy, cx = sy;
	arr.push_back(mat[cy][cx]);
	v[cy][cx] = 1;
	rep(i, 0, 4) {
		int dy = dys[i];
		int dx = dxs[i];
		while (0 <= cy + dy && cy + dy < N && 0 <= cx + dx && cx + dx < M && v[cy + dy][cx + dx] == 0) {
			arr.push_back(mat[cy + dy][cx + dx]);
			v[cy + dy][cx + dx] = 1;
			cy += dy;
			cx += dx;
		}
	}
	int miniR = R % arr.size();
	int startidx = (arr.size() - miniR) % arr.size();
	cy = sy, cx = sy;
	mat[cy][cx] = arr[startidx];
	startidx = (startidx + 1) % arr.size();
	v2[cy][cx] = 1;
	rep(i, 0, 4) {
		int dy = dys[i];
		int dx = dxs[i];
		while (0 <= cy + dy && cy + dy < N && 0 <= cx + dx && cx + dx < M && v2[cy + dy][cx + dx] == 0) {
			mat[cy + dy][cx + dx] = arr[startidx];
			startidx = (startidx + 1) % arr.size();
			v2[cy + dy][cx + dx] = 1;
			cy += dy;
			cx += dx;
		}
	}
	return;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N >> M >> R;
	rep(i, 0, N) {
		rep(j, 0, M) {
			cin >> mat[i][j];
		}
	}
	int sidx = 0;
	while (true) {
		if (v[sidx][sidx]) {
			break;
		}
		rotate(sidx++);
	}
	rep(i, 0, N) {
		rep(j, 0, M) {
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}