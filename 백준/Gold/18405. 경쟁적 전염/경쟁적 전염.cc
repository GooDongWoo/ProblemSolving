#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <cstring>
#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

struct Item {
	int v, x, y;
	bool operator<(const Item& b)const {
		return v < b.v;
	}
};
int N, K, mat[200][200], S, X, Y;
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
vector<Item> arr;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N >> K;
	rep(i, 0, N) {
		rep(j, 0, N) {
			cin >> mat[i][j];
			if (mat[i][j]) {
				arr.push_back({ mat[i][j],i,j });
			}
		}
	}
	cin >> S >> X >> Y;
	X--; Y--;
	sort(arr.begin(), arr.end());
	queue<pair<int, int>> q;
	for (const auto& nxt : arr) {
		q.push({ nxt.x,nxt.y });
	}
	int time = 0;
	while (q.size()) {
		if (time >= S) {
			break;
		}
		int miniCycle = q.size();
		rep(mini, 0, miniCycle) {
			auto curp = q.front(); q.pop();
			int cy = curp.first, cx = curp.second;
			rep(step, 0, 4) {
				int ny = cy + dys[step];
				int nx = cx + dxs[step];
				if (!(0 <= ny && ny < N && 0 <= nx && nx < N) || mat[ny][nx]) {
					continue;
				}
				mat[ny][nx] = mat[cy][cx];
				q.push({ ny,nx });
			}
		}
		time++;
	}
	cout << mat[X][Y];
	return 0;
}