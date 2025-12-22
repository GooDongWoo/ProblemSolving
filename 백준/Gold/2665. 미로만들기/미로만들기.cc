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
	int v, y, x;
	bool operator>(const Item& b) const {
		return v > b.v;
	}
};
int N, dist[50][50];
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
bool mat[50][50];
priority_queue<Item, vector<Item>, greater<>> pq;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	rep(i, 0, N) {
		string tmp;
		cin >> tmp;
		rep(j, 0, N) {
			mat[i][j] = tmp[j] - '0';
			dist[i][j] = 1e9;
		}
	}
	pq.push({ 0,0,0 });
	while (pq.size()) {
		auto curp = pq.top(); pq.pop();
		int cv = curp.v, cy = curp.y, cx = curp.x;
		if (dist[cy][cx] <= cv) {
			continue;
		}
		dist[cy][cx] = cv;
		rep(step, 0, 4) {
			int ny = cy + dys[step];
			int nx = cx + dxs[step];
			if (!(0 <= ny && ny < N && 0 <= nx && nx < N)) {
				continue;
			}
			if (mat[ny][nx]) {
				pq.push({ cv,ny,nx });
			}
			else {
				pq.push({ cv + 1,ny,nx });
			}
		}
	}
	cout << dist[N - 1][N - 1];
	return 0;
}