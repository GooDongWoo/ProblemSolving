#define rep(i,a,b) for(int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#include <cstring>
using namespace std;

struct Item {
	int cnt, y, x;
	bool operator>(const Item& b) const {
		return cnt > b.cnt;
	}
};
#define SIZE 125
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
int N, M, dp[SIZE][SIZE], mat[SIZE][SIZE], test_case;
bool v[SIZE][SIZE];
priority_queue<Item, vector<Item>, greater<>> pq;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (1) {
		test_case++;
		cin >> N;
		if (N == 0) {
			break;
		}
		rep(i, 0, N) {
			rep(j, 0, N) {
				cin >> mat[i][j];
				dp[i][j] = 1e9;
			}
		}
		memset(v, 0, sizeof(v));
		pq.push({ mat[0][0],0,0 });
		while (pq.size()) {
			auto curp = pq.top(); pq.pop();
			int cv = curp.cnt, cy = curp.y, cx = curp.x;
			if (v[cy][cx]) {
				continue;
			}

			v[cy][cx] = true;
			dp[cy][cx] = cv;

			rep(i, 0, 4) {
				int ny = cy + dys[i];
				int nx = cx + dxs[i];
				if (!((0 <= ny && ny < N) && (0 <= nx && nx < N))) {
					continue;
				}
				if (v[ny][nx]) {
					continue;
				}
				pq.push({ cv + mat[ny][nx],ny,nx });
			}
		}
		cout << "Problem " << test_case << ": " << dp[N - 1][N - 1] << '\n';
	}
	return 0;
}