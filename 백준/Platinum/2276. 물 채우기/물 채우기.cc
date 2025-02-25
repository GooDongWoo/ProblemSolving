#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cstring>

using namespace std;

typedef struct Item {
	int h, y, x;
	bool operator>(const Item& o) const {
		return (h > o.h);
	}
};
int N, M, pan[300][300], v[300][300];
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
LL ans;

bool chck(int y, int x) {
	return (0 <= y && y < N && 0 <= x && x < M && v[y][x] == 0);
}

int main() {
	fastio;
	cin >> M >> N;
	rep(i, 0, N)rep(j, 0, M) cin >> pan[i][j];
	priority_queue<Item, vector<Item>, greater<>> pq;
	rep(i, 0, N) {
		pq.push({ pan[i][0],i,0 });
		v[i][0] = 1;
		pq.push({ pan[i][M - 1],i,M - 1 });
		v[i][M - 1] = 1;
	}
	rep(i, 1, M - 1) {
		pq.push({ pan[0][i], 0,i });
		v[0][i] = 1;
		pq.push({ pan[N - 1][i],N - 1,i });
		v[N - 1][i] = 1;
	}
	while (pq.size()) {
		auto cur = pq.top();pq.pop();
		int h = cur.h, y = cur.y, x = cur.x;
		rep(dd, 0, 4) {
			int ny, nx;
			ny = y + dys[dd];
			nx = x + dxs[dd];
			if (!chck(ny, nx)) continue;
			v[ny][nx] = 1;
			if (pan[ny][nx] <= h) {
				ans += (h - pan[ny][nx]);
				pq.push({ h,ny,nx });
			}
			else {
				pq.push({ pan[ny][nx],ny,nx });
			}
		}
	}
	printf("%lld\n", ans);
}