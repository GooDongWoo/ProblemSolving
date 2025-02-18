#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cstring>
#define rep(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define LL long long

using namespace std;

int T, N, pan[20][20];

bool chck(int y, int x,int w,int h) {
	bool v[101] = {0};
	int dy = 1, dx = 1;
	int ny = y, nx = x;
	rep(re, 0, 2) {
		rep(i, 0, w) {
			ny += dy; nx += dx;
			if (v[pan[ny][nx]]) return false;
			v[pan[ny][nx]] = 1;
		}
		dx *= -1;
		rep(i, 0, h) {
			ny += dy; nx += dx;
			if (v[pan[ny][nx]]) return false;
			v[pan[ny][nx]] = 1;
		}
		dy *= -1;
	}
	return true;
}

int main() {
	cin >> T;
	rep(test_case, 1, T + 1) {
		int max1 = -1;
		cin >> N;
		rep(i, 0, N) rep(j, 0, N) cin >> pan[i][j];
		rep(i, 1, N) {
			rep(j, 1, N) {
				if (max1 >= i * 2 + j * 2) continue;
				rep(y, 0, N) {
					rep(x, 0, N) {
						if(!(y + i + j < N && x + i < N && 0<= x - j)) continue;
						if (!chck(y, x, i, j)) continue;
						max1 = max(max1, i * 2 + j * 2);
					}
				}
			}
		}
		printf("#%d %d\n",test_case,max1);
	}
	return 0;
}