#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, W, offset, arr[400][400];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	if (N == 1) {
		cout << '*';
		return 0;
	}
	W = (4 * N) - 3;
	offset = 0;
	while (N > 1) {
		int cw = (4 * N) - 3;
		int ch = (4 * N) - 1;
		rep(i, 0, cw) {
			arr[offset][i + offset] = 1;
			arr[ch - 1 + offset][i + offset] = 1;
		}
		rep(i, 0, ch) {
			arr[i + offset][offset] = 1;
			arr[i + offset][cw - 1 + offset] = 1;
		}
		arr[offset + 1][cw - 1 + offset] = 0;
		arr[offset + 2][cw - 2 + offset] = 1;
		offset += 2;
		N--;
	}
	rep(i, 0, 3) {
		arr[offset + i][offset] = 1;
	}
	rep(i, 0, W + 2) {
		if (i == 1) {
			cout << "*\n";
			continue;
		}
		rep(j, 0, W) {
			if (arr[i][j]) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}