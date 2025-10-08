#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
int N, master[100][100];
bool mat[100][100], v[100][100];

bool EdgeNodeChck(int r, int c) {
	rep(step, 0, 4) {
		int ny = r + dys[step];
		int nx = c + dxs[step];
		if (!(0 <= ny && ny < N && 0 <= nx && nx < N)) {
			continue;
		}
		if (mat[ny][nx] == 0) {
			return true;
		}
	}
	return false;
}

bool sidechck(int r, int c) {
	rep(step, 0, 4) {
		int ny = r + dys[step];
		int nx = c + dxs[step];
		if (!(0 <= ny && ny < N && 0 <= nx && nx < N)) {
			continue;
		}
		if (master[ny][nx] != 0 && master[ny][nx] != master[r][c]) {
			return true;
		}
	}
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	memset(v, 0, sizeof(v));
	rep(i, 0, N) {
		rep(j, 0, N) {
			cin >> mat[i][j];
		}
	}
	int masterNum = 0;
	queue<pair<int, int>> q;
	vector<pair<int, int>> edgenodes;
	edgenodes.reserve(N * N);
	rep(i, 0, N) {
		rep(j, 0, N) {
			if (mat[i][j] && !v[i][j]) {
				master[i][j] = ++masterNum;
				v[i][j] = 1;
				q.push({ i,j });
				while (q.size()) {
					auto curp = q.front(); q.pop();
					int cy = curp.first, cx = curp.second;
					if (EdgeNodeChck(cy, cx)) {
						edgenodes.push_back({ cy,cx });
					}
					rep(step, 0, 4) {
						int ny = cy + dys[step];
						int nx = cx + dxs[step];
						if (!(0 <= ny && ny < N && 0 <= nx && nx < N) || !mat[ny][nx] || v[ny][nx]) {
							continue;
						}
						v[ny][nx] = 1;
						master[ny][nx] = master[i][j];
						q.push({ ny,nx });
					}
				}
			}
		}
	}
	for (const auto& item : edgenodes) {
		q.push(item);
	}
	int timer = 0;
	while (q.size()) {
		timer++;
		int miniCycle = q.size();
		vector<pair<int, int>> candidates;
		rep(tmp__, 0, miniCycle) {
			auto curp = q.front(); q.pop();
			int cy = curp.first, cx = curp.second;
			rep(step, 0, 4) {
				int ny = cy + dys[step];
				int nx = cx + dxs[step];
				if (!(0 <= ny && ny < N && 0 <= nx && nx < N) || mat[ny][nx]) {
					continue;
				}//-> 격자 내부 && 바다이다.
				if (v[ny][nx]) {
					if (master[ny][nx] != 0 && master[ny][nx] != master[cy][cx]) {//최소거리가 홀수일 때 nxt가 master가 서로 다르고 v[][]는 -1이 아니라는거겠지
						cout << 2 * timer - 1;
						return 0;
					}
					else {
						continue;
					}
				}
				v[ny][nx] = 1;
				master[ny][nx] = master[cy][cx];
				q.push({ ny,nx });
				candidates.push_back({ ny,nx });
			}
		}
		for (const auto& item : candidates) {
			if (sidechck(item.first, item.second)) {
				cout << 2 * timer;
				return 0;
			}
		}
	}
	return 0;
}
