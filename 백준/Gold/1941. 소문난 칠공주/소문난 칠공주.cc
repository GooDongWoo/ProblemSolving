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

bool mat[5][5];
int cnter, ans;
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
vector<int> cur;
int chck() {
	if (cur.size() > 7) {
		return 0;
	}
	
	queue<pair<int, int>> q;
	bool v[5][5];
	memset(v, 0, sizeof(v));
	q.push({ cur[0] / 5, cur[0] % 5 });
	v[cur[0] / 5][cur[0] % 5] = 1;
	int minicnter = 1;
	while (q.size()) {
		auto curp = q.front(); q.pop();
		int cy = curp.first, cx = curp.second;
		rep(step, 0, 4) {
			int ny = cy + dys[step];
			int nx = cx + dxs[step];
			if (!(0 <= ny && ny < 5 && 0 <= nx && nx < 5) || v[ny][nx]) {
				continue;
			}
			bool isIn = false;
			for (const int& item : cur) {
				if (item == ny * 5 + nx) {
					isIn = true;
					break;
				}
			}
			if (!isIn) {
				continue;
			}
			minicnter++;
			v[ny][nx] = 1;
			q.push({ny,nx});
		}
	}
	return minicnter == 7;
}

void bt(int idx, int nxtIdx) {
	if (idx >= 7) {
		if (cnter >= 4) {
			ans += chck();
		}
		return;
	}
	rep(nxt, nxtIdx, 25) {
		int y = nxt / 5, x = nxt % 5;
		cur.push_back(nxt);
		cnter += mat[y][x];
		bt(idx + 1, nxt + 1);
		cur.pop_back();
		cnter -= mat[y][x];
	}
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cur.reserve(10);
	rep(i, 0, 5) {
		string inp;
		cin >> inp;
		rep(j, 0, 5) {
			mat[i][j] = (inp[j] == 'S');
		}
	}
	bt(0, 0);
	cout << ans<<'\n';
	return 0;
}