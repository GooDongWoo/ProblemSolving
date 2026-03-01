#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <unordered_map>

#define rep(i, a, b) for (int i=a;i<b;++i)
using LL = long long;
using namespace std;

struct Node {
	int y, x, k, v;
	bool operator>(const Node& b)const {
		return v > b.v;
	}
};
int N, M, K, v[1000][1000][11];
bool mat[1000][1000];
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	cin >> N >> M >> K;
	rep(i, 0, N) {
		string line;
		cin >> line;
		rep(j, 0, M) {
			if (line[j] == '0') {
				mat[i][j] = 0;
			}
			else {
				mat[i][j] = 1;
			}
		}
	}

	priority_queue<Node, vector<Node>, greater<>> pq;
	v[0][0][0] = 1;
	pq.push({ 0,0,0,1 });
	while (pq.size()) {
		auto curp = pq.top(); pq.pop();
		int cy = curp.y, cx = curp.x, ck = curp.k, cv = curp.v;
		rep(step, 0, 4) {
			int ny = cy + dys[step];
			int nx = cx + dxs[step];

			if (!(0 <= ny && ny < N && 0 <= nx && nx < M)) {
				continue;
			}

			if (mat[ny][nx] && ck + 1 > K) {
				continue;
			}

			// 이미 방문 했는가?
			if (mat[ny][nx] && ck + 1 <= K && v[ny][nx][ck + 1] > 0) {
				continue;
			}
			if (!mat[ny][nx] && v[ny][nx][ck] > 0) {
				continue;
			}

			// 벽이면 낮에 뚫을 수 있는가?
			if (mat[ny][nx]) {
				if (v[cy][cx][ck] & 1) {
					v[ny][nx][ck + 1] = v[cy][cx][ck] + 1;
				}
				else {
					v[ny][nx][ck + 1] = v[cy][cx][ck] + 2;
				}
				pq.push({ ny,nx,ck + 1,v[ny][nx][ck + 1] });
			}
			else {
				v[ny][nx][ck] = v[cy][cx][ck] + 1;
				pq.push({ ny,nx,ck,v[ny][nx][ck] });
			}
		}
	}
	int val = 1e9;
	rep(i, 0, K + 1) {
		if (v[N - 1][M - 1][i] == 0)
			continue;
		val = min(val, v[N - 1][M - 1][i]);
	}
	cout << (val == 1e9 ? -1 : val);
	return 0;
}