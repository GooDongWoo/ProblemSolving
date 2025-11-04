#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N, M, nationNum[10][10], allChckCnter, ans;
bool isLand[10][10], v[6];
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
vector<pair<int, int>> horizonNations[10], verticalNations[10];
vector<vector<pair<int, int>>> adjv;

void bfs(int sy, int sx, int num) {
	queue<pair<int, int>> q;
	nationNum[sy][sx] = num;
	horizonNations[sy].push_back({ sx,num });
	verticalNations[sx].push_back({ sy,num });
	q.push({ sy,sx });
	while (q.size()) {
		auto curp = q.front(); q.pop();
		int cy = curp.first, cx = curp.second;
		rep(step, 0, 4) {
			int ny = cy + dys[step];
			int nx = cx + dxs[step];
			if (!(0 <= ny && ny < N && 0 <= nx && nx < M) || !isLand[ny][nx] || nationNum[ny][nx]) {
				continue;
			}
			nationNum[ny][nx] = num;
			horizonNations[ny].push_back({ nx,num });
			verticalNations[nx].push_back({ ny,num });
			q.push({ ny,nx });
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N >> M;
	rep(i, 0, N) {
		rep(j, 0, M) {
			cin >> isLand[i][j];
		}
	}
	int landNum = 0;
	rep(i, 0, N) {
		rep(j, 0, M) {
			if (!isLand[i][j] || nationNum[i][j]) { continue; }
			bfs(i, j, ++landNum);
		}
	}
	adjv.resize(landNum);
	rep(i, 0, 10) {
		sort(horizonNations[i].begin(), horizonNations[i].end());
		if (horizonNations[i].size() > 1) {
			int befNation = horizonNations[i][0].second;
			rep(j, 1, horizonNations[i].size()) {
				if (befNation != horizonNations[i][j].second) {
					int nxtNation = horizonNations[i][j].second;
					if (horizonNations[i][j].first - horizonNations[i][j - 1].first > 2) {
						adjv[befNation - 1].push_back({ horizonNations[i][j].first - horizonNations[i][j - 1].first - 1,nxtNation - 1 });
						adjv[nxtNation - 1].push_back({ horizonNations[i][j].first - horizonNations[i][j - 1].first - 1,befNation - 1 });
					}
					befNation = horizonNations[i][j].second;
				}
			}
		}
		sort(verticalNations[i].begin(), verticalNations[i].end());
		if (verticalNations[i].size() > 1) {
			int befNation = verticalNations[i][0].second;
			rep(j, 1, verticalNations[i].size()) {
				if (befNation != verticalNations[i][j].second) {
					int nxtNation = verticalNations[i][j].second;
					if (verticalNations[i][j].first - verticalNations[i][j - 1].first > 2) {
						adjv[befNation - 1].push_back({ verticalNations[i][j].first - verticalNations[i][j - 1].first - 1,nxtNation - 1 });
						adjv[nxtNation - 1].push_back({ verticalNations[i][j].first - verticalNations[i][j - 1].first - 1,befNation - 1 });
					}
					befNation = verticalNations[i][j].second;
				}
			}
		}
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0,0 });
	while (pq.size()) {
		auto curp = pq.top(); pq.pop();
		int cw = curp.first, cur = curp.second;
		if (v[cur]) { continue; }
		allChckCnter++;
		v[cur] = true;
		ans += cw;
		for (auto& nxtp : adjv[cur]) {
			int nw = nxtp.first, nxt = nxtp.second;
			if (v[nxt]) { continue; }
			pq.push({ nw ,nxt });
		}
	}
	cout << ((allChckCnter == landNum) ? ans : -1);
	return 0;
}