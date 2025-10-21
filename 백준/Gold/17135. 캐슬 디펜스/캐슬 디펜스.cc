#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, M, D, mat[15][15], ans;
vector<int> candidates;
int dys[] = { 0,-1,0 };
int dxs[] = { -1,0,1 };

void run() {
	int kills = 0;
	int cmat[15][15];
	rep(i, 0, N) {
		rep(j, 0, M) {
			cmat[i][j] = mat[i][j];
		}
	}
	rep(i, 0, N) {
		set<pair<int, int>> s1;
		for (int x : candidates) {
			int v[15][15];
			memset(v, 0, sizeof(v));
			queue<pair<int, int>> q;
			v[N - 1][x] = 1;
			q.push({ N - 1,x });
			while (q.size()) {
				auto curp = q.front(); q.pop();
				int cy = curp.first, cx = curp.second;
				if (cmat[cy][cx]) {
					s1.insert({ cy,cx });
					break;
				}
				rep(step, 0, 3) {
					int ny = cy + dys[step];
					int nx = cx + dxs[step];
					if (!(0 <= ny && ny < N && 0 <= nx && nx < M) || v[ny][nx] || v[cy][cx] + 1 > D) {
						continue;
					}
					v[ny][nx] = v[cy][cx] + 1;
					q.push({ ny,nx });
				}
			}
		}
		for (const auto npair : s1) {
			cmat[npair.first][npair.second] = 0;
		}
		kills += s1.size();
		rep(i, 1, N) {
			memcpy(cmat[N - i], cmat[N - 1 - i], sizeof(int) * M);
		}
		memset(cmat, 0, sizeof(int) * M);
	}
	ans = max(ans, kills);
}

void bt(int idx, int st) {
	if (idx == 3) {
		run();
		return;
	}
	else {
		rep(i, st, M) {
			candidates.push_back(i);
			bt(idx + 1, i + 1);
			candidates.pop_back();
		}
	}
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N >> M >> D;
	rep(i, 0, N) {
		rep(j, 0, M) {
			cin >> mat[i][j];
		}
	}
	bt(0, 0);
	cout << ans;
	return 0;
}