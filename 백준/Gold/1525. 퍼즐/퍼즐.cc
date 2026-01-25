#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;
using LL = long long;

const int MAX = 3;
const LL ANS = 123456780ll;
int mat[MAX][MAX];
int dys[] = { 1,0,-1,0 };
int dxs[] = { 0,1,0,-1 };
unordered_map<LL, int> dict;

LL F(int (*parr)[3]) {
	LL tmp = 0;
	rep(i, 0, MAX) {
		rep(j, 0, MAX) {
			tmp *= 10;
			tmp += parr[i][j];
		}
	}
	return tmp;
}

void RF(LL val, int(*parr)[3]) {
	rep(i, 0, MAX) {
		rep(j, 0, MAX) {
			parr[2 - i][2 - j] = val % 10;
			val /= 10;
		}
	}
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	rep(i, 0, MAX) {
		rep(j, 0, MAX) {
			cin >> mat[i][j];
		}
	}

	// bfs
	queue<LL> q;
	LL start = F(mat);
	dict[start] = 1;
	q.push(start);
	while (q.size()) {
		LL cur = q.front(); q.pop();
		if (cur == ANS) {
			cout << dict[cur] - 1;
			return 0;
		}
		int tmp[3][3], cy, cx;
		RF(cur, tmp);
		rep(i, 0, MAX) {
			rep(j, 0, MAX) {
				if (tmp[i][j] == 0) {
					cy = i;
					cx = j;
					break;
				}
			}
		}
		rep(step, 0, 4) {
			int ny = cy + dys[step];
			int nx = cx + dxs[step];
			if (!(0 <= ny && ny < MAX && 0 <= nx && nx < MAX)) {
				continue;
			}
			int nxt[3][3];
			rep(i, 0, MAX) {
				rep(j, 0, MAX) {
					nxt[i][j] = tmp[i][j];
				}
			}
			swap(nxt[cy][cx], nxt[ny][nx]);
			LL nxtval = F(nxt);
			if (dict.count(nxtval) > 0) {
				continue;
			}
			dict[nxtval] = dict[cur] + 1;
			q.push(nxtval);
            if (nxtval == ANS) {
				cout << dict[nxtval] - 1;
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}