#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;

int N, mat[50][9], ans, simul[9];
bool v[9];

void run() {
	int score = 0;
	int gameIdx = 0;
	int sunsooIdx = 0;
	while (gameIdx < N) {
		int outCnter = 0;
		bool jari[3] = { 0,0,0 };
		while (outCnter < 3) {
			switch (mat[gameIdx][simul[sunsooIdx]]) {
			case(1): {
				if (jari[2]) {
					score++;
					jari[2] = 0;
				}
				if (jari[1]) {
					jari[2] = 1;
					jari[1] = 0;
				}
				if (jari[0]) {
					jari[1] = 1;
					jari[0] = 0;
				}
				jari[0] = 1;
				break;
			}
			case(2): {
				if (jari[2]) {
					score++;
					jari[2] = 0;
				}
				if (jari[1]) {
					score++;
					jari[1] = 0;
				}
				if (jari[0]) {
					jari[2] = 1;
					jari[0] = 0;
				}
				jari[1] = 1;
				break;
			}
			case(3): {
				if (jari[2]) {
					score++;
					jari[2] = 0;
				}
				if (jari[1]) {
					score++;
					jari[1] = 0;
				}
				if (jari[0]) {
					score++;
					jari[0] = 0;
				}
				jari[2] = 1;
				break;
			}
			case(4): {
				if (jari[2]) {
					score++; jari[2] = 0;
				}
				if (jari[1]) {
					score++; jari[1] = 0;
				}
				if (jari[0]) {
					score++; jari[0] = 0;
				}
				score++;
				break;
			}
			case(0): {
				outCnter++;
				break;
			}
			}
			sunsooIdx = (sunsooIdx + 1) % 9;
		}
		gameIdx++;
	}
	ans = max(ans, score);
}

void bt(int idx) {
	if (idx == 3) {
		bt(idx + 1);
		return;
	}
	if (idx >= 9) {
		run();
		return;
	}
	rep(i, 1, 9) {
		if (v[i]) continue;
		v[i] = 1;
		simul[idx] = i;
		bt(idx + 1);
		v[i] = 0;
	}
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cout.tie(NULL);

	cin >> N;
	rep(i, 0, N) {
		rep(j, 0, 9) {
			cin >> mat[i][j];
		}
	}
	bt(0);
	cout << ans;
	return 0;
}