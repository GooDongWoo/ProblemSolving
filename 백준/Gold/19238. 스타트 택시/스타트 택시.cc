#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;
using LL = long long;

struct customer {
	int ey, ex;
};
int N, M, O, sy, sx, v[20][20], cs[20][20], cnter;
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
bool mat[20][20];
customer arr[400];

int main() {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> M >> O;
	rep(i, 0, N) {
		rep(j, 0, N) {
			cin >> mat[i][j];
		}
	}
	cin >> sy >> sx;
	sy--; sx--;
	memset(cs, -1, sizeof(cs));
	rep(i, 0, M) {
		int msy, msx;
		cin >> msy >> msx >> arr[i].ey >> arr[i].ex;
		msy--; msx--; arr[i].ey--; arr[i].ex--;
		cs[msy][msx] = i;
	}

	// 모든 승객들을 보낼때까지
	while (cnter < M) {
		// 현재 택시 위치에서 bfs 돌려서 최단거리 중에서 제일 위쪽, 왼쪽에 있는 승객을 찾는다.
		memset(v, 0, sizeof(v));
		vector<pair<int, int>> candidates;
		queue<pair<int, int>> q;
		q.push({ sy,sx });
		v[sy][sx] = 1;
		bool isFind = false;
		while (q.size() && !isFind) {
			int miniCycle = q.size();
			rep(mini_step, 0, miniCycle) {
				auto curp = q.front(); q.pop();
				int cy = curp.first, cx = curp.second;
				// 해당 미니사이클에서 방문한 곳이 승객이면 대기 벡터에 추가함.
				if (cs[cy][cx] >= 0) {
					candidates.push_back({ cy,cx });
					isFind = true;
				}

				// 찾았으면 다음 루프 돌릴 필요 없음;
				if (isFind) {
					continue;
				}
				rep(step, 0, 4) {
					int ny = cy + dys[step];
					int nx = cx + dxs[step];
					if (!(0 <= ny && ny < N && 0 <= nx && nx < N) || mat[ny][nx] || v[ny][nx]) {
						continue;
					}
					v[ny][nx] = v[cy][cx] + 1;
					q.push({ ny,nx });
				}
			}
		}
		sort(candidates.begin(), candidates.end());
		if (candidates.size()) {
			//승객을 찾았는데 거기까지 갈 수 있는지를 확인한다.
			if (v[candidates[0].first][candidates[0].second] - 1 < O) {
				//승객을 보내고 O를 감소시킨다.
				O -= v[candidates[0].first][candidates[0].second] - 1;
				sy = candidates[0].first;
				sx = candidates[0].second;
			}
			else {
				//갈수 없으면 종료
				cout << -1;
				return 0;
			}
		}
		else {
			// cnter < M인데 찾을 수가 없으니까 출력 -1하고 종료 해야 한다.
			cout << -1;
			return 0;
		}

		//그 승객을 데리고 해당 승객의 목적지에 대해서 bfs로 최단거리를 계산한다.
		int csidx = cs[sy][sx];
		int ey = arr[csidx].ey, ex = arr[csidx].ex;

		memset(v, 0, sizeof(v));
		queue<pair<int, int>> q2;
		q2.push({ sy,sx });
		v[sy][sx] = 1;
		isFind = false;
		while (q2.size() && !isFind) {
			auto curp = q2.front(); q2.pop();
			int cy = curp.first, cx = curp.second;
			rep(step, 0, 4) {
				int ny = cy + dys[step];
				int nx = cx + dxs[step];
				if (!(0 <= ny && ny < N && 0 <= nx && nx < N) || mat[ny][nx] || v[ny][nx]) {
					continue;
				}
				v[ny][nx] = v[cy][cx] + 1;
				q2.push({ ny,nx });
				if (ny == ey && nx == ex) {
					isFind = true;
					break;
				}
			}
		}
		int cost = v[ey][ex] - 1;
		// 물리적으로 막혀있어서 or 연료가 미만이라 목적지까지 보내고 못 보내면 return -1
		if (cost <= 0 || cost > O) {
			cout << -1;
			return 0;
		}
		// 택시 위치 업데이트, 이동 시킨 승객의 시작 위치를 cs를 -1로 초기화한다.
		O += cost;
		cs[sy][sx] = -1;
		sy = ey;
		sx = ex;
		cnter++;
	}
	cout << O;
	return 0;
}