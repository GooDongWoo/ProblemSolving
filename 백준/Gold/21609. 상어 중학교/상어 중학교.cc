#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <unordered_map>
#include <cmath>
#include <string>
#include <cstring>
#include <stdexcept>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;
using LL = long long;
using UI = unsigned int;

struct Ptem {
	int mujigaes, y, x;
	bool operator<(const Ptem& b) const {
		if (mujigaes != b.mujigaes) {
			return mujigaes < b.mujigaes;
		}
		if (y != b.y) {
			return y < b.y;
		}
		return x < b.x;
	}
};
int N, M, score;
vector<vector<int>> mat; // 비어있는 값은 -2로 한다.
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };


vector<vector<int>> RotateCCW(const vector<vector<int>>& arr, int row, int col) {
	vector<vector<int>> ret;
	ret.resize(col);
	rep(i, 0, col) {
		rep(j, 0, row) {
			ret[i].push_back(arr[j][col - 1 - i]);
		}
	}
	return ret;
}

void Gravity(vector<vector<int>>& arr, int row, int col) {
	rep(k, 0, row - 1) {
		rep(i, 0, row - 1) {
			rep(j, 0, col) {
				if (arr[row - 1 - i][j] == -2 && arr[row - 2 - i][j] != -1) {
					swap(arr[row - 1 - i][j], arr[row - 2 - i][j]);
				}
			}
		}
	}
}

bool FindRowCol(const vector<vector<int>>& arr, int row, int col, int& refRow, int& refCol) {
	bool isNormalVisit[20][20];
	memset(isNormalVisit, 0, sizeof(isNormalVisit));

	refRow = -1;
	refCol = -1;
	int cnter = 1;

	priority_queue<Ptem> pq;
	rep(i, 0, row) {
		rep(j, 0, col) {
			if (arr[i][j] <= 0 || isNormalVisit[i][j]) {
				continue;
			}
			// 이제 이 값은 무조건 일반 블록임;;
			// 이제 bfs 돌리면서 해당 값이 기준 값일 때 최대 몇인지를 알아낸다.
			bool v[20][20];
			memset(v, 0, sizeof(v));

			int miniCnter = 1;
			int mujigaesCnt = 0;
			queue<pair<int, int>> q;
			int curVal = arr[i][j];
			v[i][j] = 1;
			q.push({ i,j });
			while (q.size()) {
				auto curp = q.front(); q.pop();
				int cy = curp.first, cx = curp.second;
				rep(step, 0, 4) {
					int ny = cy + dys[step];
					int nx = cx + dxs[step];
					if (!(0 <= ny && ny < row && 0 <= nx && nx < col) || v[ny][nx] ||
						(arr[ny][nx] < 0) || (arr[ny][nx] != 0 && arr[ny][nx] != curVal)) {
						continue;
					}
					if (arr[ny][nx] != 0) {
						isNormalVisit[ny][nx] = 1;
					}
					else {
						mujigaesCnt++;
					}
					q.push({ ny,nx });
					v[ny][nx] = 1;
					miniCnter++;
				}
			}
			if (miniCnter > cnter) {
				cnter = miniCnter;
				pq = priority_queue<Ptem>();
				pq.push({ mujigaesCnt, i, j });
			}
			else if (cnter > 1 && miniCnter == cnter) {
				pq.push({ mujigaesCnt, i, j });
			}
		}
	}
	if (pq.size()) {
		refRow = pq.top().y;
		refCol = pq.top().x;
		return true;
	}
	else {
		return false;
	}
}

int deleteGroup(vector<vector<int>>& arr, int row, int col, int targetRow, int targetCol) {
	bool v[20][20];
	memset(v, 0, sizeof(v));

	int miniCnter = 1;
	queue<pair<int, int>> q;
	v[targetRow][targetCol] = 1;
	int curVal = arr[targetRow][targetCol];
	q.push({ targetRow,targetCol });
	while (q.size()) {
		auto curp = q.front(); q.pop();
		int cy = curp.first, cx = curp.second;
		arr[cy][cx] = -2;
		rep(step, 0, 4) {
			int ny = cy + dys[step];
			int nx = cx + dxs[step];
			if (!(0 <= ny && ny < row && 0 <= nx && nx < col) || v[ny][nx] ||
				(arr[ny][nx] < 0) || (arr[ny][nx] != 0 && arr[ny][nx] != curVal)) {
				continue;
			}
			q.push({ ny,nx });
			v[ny][nx] = 1;
			miniCnter++;
		}
	}
	return miniCnter;
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> M;
	mat.resize(N);
	rep(i, 0, N) {
		rep(j, 0, N) {
			int val;
			cin >> val;
			mat[i].push_back(val);
		}
	}

	int cRow, cCol;
	while (FindRowCol(mat, mat.size(), mat[0].size(), cRow, cCol)) {
		int numDeleted = deleteGroup(mat, mat.size(), mat[0].size(), cRow, cCol);
		score += numDeleted * numDeleted;

		Gravity(mat, mat.size(), mat[0].size());

		mat = RotateCCW(mat, mat.size(), mat[0].size());

		Gravity(mat, mat.size(), mat[0].size());
	}
	cout << score;

	return 0;
}