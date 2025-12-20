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

const int N = 10;
int ans = 1e9, mini = 0;
int bag[5] = { 5,5,5,5,5 }; // -> 5,4,3,2,1;
bool mat[10][10];
vector<pair<int, int>> points;

bool chck(int y, int x, int width) {
	int w = width - 1;
	if (y + w >= 10 || x + w >= 10) {
		return false;
	}
	rep(i, 0, width) {
		rep(j, 0, width) {
			if (!mat[y + i][x + j]) {
				return false;
			}
		}
	}
	return true;
}

void put1(int y, int x, int width, int val) {
	rep(i, 0, width) {
		rep(j, 0, width) {
			mat[y + i][x + j] = val;
		}
	}
	return;
}

void bt(int idx) {
	if (idx >= points.size()) {
		ans = min(ans, mini);
		return;
	}
	int y = points[idx].first;
	int x = points[idx].second;
	if (!mat[y][x]) {
		bt(idx + 1);
	}
	int choice = 0;
	rep(i, 0, 5) {
		if (bag[i] > 0 && chck(y, x, (5 - i))) {
			mini++;
			bag[i]--;
			put1(y, x, 5 - i, 0);
			bt(idx + 1);
			mini--;
			bag[i]++;
			put1(y, x, 5 - i, 1);

		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	rep(i, 0, N) {
		rep(j, 0, N) {
			cin >> mat[i][j];
			if (mat[i][j]) {
				points.push_back({ i,j });
			}
		}
	}
	bt(0);
	cout << ((ans >= 1e9) ? -1 : ans);
	return 0;
}