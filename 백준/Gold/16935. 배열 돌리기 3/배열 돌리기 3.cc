#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;
using LL = long long;

int N, M, R;
vector<vector<int>> mat1, mat2;

void F1() {
	N = mat1.size();
	M = mat1[0].size();
	mat2.resize(N);
	rep(i, 0, N) mat2[i].resize(M);

	rep(i, 0, N) {
		rep(j, 0, M) {
			mat2[i][j] = mat1[N - 1 - i][j];
		}
	}
	swap(mat1, mat2);
}

void F2() {
	N = mat1.size();
	M = mat1[0].size();
	mat2.resize(N);
	rep(i, 0, N) mat2[i].resize(M);

	rep(i, 0, N) {
		rep(j, 0, M) {
			mat2[i][j] = mat1[i][M - 1 - j];
		}
	}
	swap(mat1, mat2);
}

void F9() {
	N = mat1.size();
	M = mat1[0].size();
	mat2.resize(M);
	rep(i, 0, M) mat2[i].resize(N);

	rep(i, 0, M) {
		rep(j, 0, N) {
			mat2[i][j] = mat1[j][i];
		}
	}
	swap(mat1, mat2);
}

void F3() {
	F9();
	F2();
}

void F4() {
	F2();
	F9();
}

void F5() {
	N = mat1.size();
	M = mat1[0].size();
	mat2.resize(N);
	rep(i, 0, N) mat2[i].resize(M);
	int n = N / 2;
	int m = M / 2;

	rep(i, 0, n) {
		rep(j, 0, m) {
			mat2[i][j] = mat1[i + n][j];
		}
	}
	rep(i, 0, n) {
		rep(j, m, M) {
			mat2[i][j] = mat1[i][j - m];
		}
	}
	rep(i, n, N) {
		rep(j, 0, m) {
			mat2[i][j] = mat1[i][j + m];
		}
	}
	rep(i, n, N) {
		rep(j, m, M) {
			mat2[i][j] = mat1[i - n][j];
		}
	}
	swap(mat1, mat2);
}

void F6() {
	N = mat1.size();
	M = mat1[0].size();
	mat2.resize(N);
	rep(i, 0, N) mat2[i].resize(M);
	int n = N / 2;
	int m = M / 2;

	rep(i, 0, n) {
		rep(j, 0, m) {
			mat2[i][j] = mat1[i][j + m];
		}
	}
	rep(i, 0, n) {
		rep(j, m, M) {
			mat2[i][j] = mat1[i + n][j];
		}
	}
	rep(i, n, N) {
		rep(j, 0, m) {
			mat2[i][j] = mat1[i - n][j];
		}
	}
	rep(i, n, N) {
		rep(j, m, M) {
			mat2[i][j] = mat1[i][j - m];
		}
	}
	swap(mat1, mat2);
}

void (*fs[6])() = { F1, F2,F3,F4,F5,F6 };

int main() {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> M >> R;

	mat1.resize(N);
	rep(i, 0, N) mat1[i].resize(M);

	rep(i, 0, N) {
		rep(j, 0, M) {
			cin >> mat1[i][j];
		}
	}

	rep(i, 0, R) {
		int a;
		cin >> a; a--;
		fs[a]();
	}

	N = mat1.size();
	M = mat1[0].size();
	rep(i, 0, N) {
		rep(j, 0, M) {
			cout << mat1[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}