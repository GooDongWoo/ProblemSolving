#define rep(i,a,b) for(int i=a;i<b;++i)
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int R, C;
vector<string> grid;
queue<pair<int, int>> water_q;
int dys[] = { 1, 0, -1, 0 };
int dxs[] = { 0, 1, 0, -1 };

#define SIZE 2250000
int parent[SIZE], childs[SIZE];

void init() {
	rep(i, 0, SIZE) {
		parent[i] = i;
		childs[i] = 1;
	}
}

int mfind(int num) {
	if (parent[num] != num) {
		parent[num] = mfind(parent[num]);
	}
	return parent[num];
}

void munion(int a, int b) {
	int pa = mfind(a);
	int pb = mfind(b);
	if (pa == pb) {
		return;
	}
	if (childs[pa] < childs[pb]) {
		swap(pa, pb);
	}
	childs[pa] += childs[pb];
	parent[pb] = pa;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> R >> C;

	grid.resize(R);
	rep(i, 0, R) {
		cin >> grid[i];
	}

	init();

	vector<pair<int, int>> swans;
	rep(i, 0, R) {
		rep(j, 0, C) {
			if (grid[i][j] == 'L') {
				swans.push_back({ i, j });
				grid[i][j] = '.';
			}
		}
	}

	rep(i, 0, R) {
		rep(j, 0, C) {
			if (grid[i][j] == '.') {
				bool adjacent_to_ice = false;
				rep(k, 0, 4) {
					int ni = i + dys[k];
					int nj = j + dxs[k];
					if (ni >= 0 && ni < R && nj >= 0 && nj < C) {
						if (grid[ni][nj] == '.') {
							munion(i * C + j, ni * C + nj);
						}
						else if (grid[ni][nj] == 'X') {
							adjacent_to_ice = true;
						}
					}
				}
				if (adjacent_to_ice) {
					water_q.push({ i, j });
				}
			}
		}
	}

	int day = 0;

	if (mfind(swans[0].first * C + swans[0].second) == mfind(swans[1].first * C + swans[1].second)) {
		cout << day << endl;
		return 0;
	}

	while (true) {
		day++;
		queue<pair<int, int>> next_water_q;

		while (water_q.size()) {
			auto curp = water_q.front();
			int cy = curp.first;
			int cx = curp.second;
			water_q.pop();

			rep(j, 0, 4) {
				int ny = cy + dys[j];
				int nx = cx + dxs[j];

				if (ny >= 0 && ny < R && nx >= 0 && nx < C && grid[ny][nx] == 'X') {
					grid[ny][nx] = '.';


					rep(k, 0, 4) {
						int nny = ny + dys[k];
						int nnx = nx + dxs[k];
						if (nny >= 0 && nny < R && nnx >= 0 && nnx < C && grid[nny][nnx] == '.') {
							munion(ny * C + nx, nny * C + nnx);
						}
					}

					bool adjacent_to_ice = false;
					rep(k, 0, 4) {
						int nny = ny + dys[k];
						int nnx = nx + dxs[k];
						if (nny >= 0 && nny < R && nnx >= 0 && nnx < C && grid[nny][nnx] == 'X') {
							adjacent_to_ice = true;
							break;
						}
					}
					if (adjacent_to_ice) {
						next_water_q.push({ ny, nx });
					}
				}
			}
		}
		water_q = next_water_q;

		if (mfind(swans[0].first * C + swans[0].second) == mfind(swans[1].first * C + swans[1].second)) {
			cout << day << endl;
			return 0;
		}
	}

	return 0;
}