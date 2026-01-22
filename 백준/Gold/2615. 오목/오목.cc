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

const int MAX = 19;
int mat[MAX][MAX];
int dys[] = { 1,1,0,-1 };
int dxs[] = { 0,1,1,1 };

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	rep(i, 0, MAX) {
		rep(j, 0, MAX) {
			cin >> mat[i][j];
		}
	}
	rep(i, 0, MAX) {
		rep(j, 0, MAX) {
			if (mat[i][j]) {
				rep(step, 0, 4) {
					int ny = i - dys[step];
					int nx = j - dxs[step];
					if (0 <= ny && ny < MAX && 0 <= nx && nx < MAX && mat[ny][nx] == mat[i][j]) {
						continue;
					}
					ny = i; nx = j;
					bool isGo = true;
					rep(dt, 0, 4) {
						ny += dys[step];
						nx += dxs[step];
						if (!(0 <= ny && ny < MAX && 0 <= nx && nx < MAX && mat[ny][nx] == mat[i][j])) {
							isGo = false;
							break;
						}
					}
					if (isGo) {// +5체크하고 없어야만 정답
						ny += dys[step];
						nx += dxs[step];
						if ((0 <= ny && ny < MAX && 0 <= nx && nx < MAX && mat[ny][nx] == mat[i][j]) && mat[ny][nx] == mat[i][j]) {
							isGo = false;
							continue;
						}
					}
					if (isGo) {
						cout << (mat[i][j] == 1 ? 1 : 2) << '\n';
						cout << i + 1 << ' ' << j + 1;
						return 0;
					}
				}
			}
		}
	}
	cout << 0;
	return 0;
}