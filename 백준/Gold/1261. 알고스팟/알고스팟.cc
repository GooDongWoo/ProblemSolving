#define rep(i,a,b) for(int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

struct Item {
	int cnt, y, x;
	bool operator<(const Item& b) const {
		return cnt < b.cnt;
	}
	bool operator>(const Item& b) const {
		return cnt > b.cnt;
	}
};
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
int N, M, dp[100][100];
bool mat[100][100], v[100][100];
priority_queue<Item, vector<Item>, greater<>> pq;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> M >> N;
	rep(i, 0, N) {
		string tmp;
		cin >> tmp;
		rep(j, 0, M) {
			mat[i][j] = tmp[j] - '0';
			dp[i][j] = 1e9;
		}
	}
	dp[0][0] = 0;
	pq.push({ 0,0,0 });
	while (pq.size()) {
		auto curp = pq.top();
		pq.pop();
		int cv, cy, cx;
		cv = curp.cnt;
		cy = curp.y;
		cx = curp.x;
		if (v[cy][cx]) {
			continue;
		}
		v[cy][cx] = 1;
		dp[cy][cx] = cv;
		rep(i, 0, 4) {
			int ny, nx;
			ny = cy + dys[i];
			nx = cx + dxs[i];
			if (!((0 <= ny && ny < N) && (0 <= nx && nx < M))) {
				continue;
			}
			if (v[ny][nx]) {
				continue;
			}
			if (mat[ny][nx]) {
				pq.push({ cv + 1,ny,nx });
			}
			else {
				pq.push({ cv,ny,nx });
			}

		}
	}
	cout << dp[N - 1][M - 1];
	return 0;
}