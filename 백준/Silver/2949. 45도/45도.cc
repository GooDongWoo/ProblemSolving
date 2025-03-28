#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define LL long long

using namespace std;

int R, C, num;
vector<vector<char>> arr;

vector<vector<char>> rotate90(const vector<vector<char>>& mat) {
	int N, M;
	N = mat.size();
	M = mat[0].size();
	vector<vector<char>> res;
	res.resize(M);
	rep(i, 0, M)
		res[i].resize(N);
	rep(i, 0, N)
		rep(j, 0, M)
		res[j][N - 1 - i] = mat[i][j];
	return res;
}

vector<vector<char>> rotate45(const vector<vector<char>>& mat) {
	int N, M, r, c, indent, incre;
	N = mat.size();
	M = mat[0].size();
	vector<vector<char>> res;
	indent = N - 1;
	incre = -1;
	rep(i, 0, N + M - 1) {
		r = i;
		vector<char> tmp;
		rep(i, 0, indent)
			tmp.push_back(' ');
		indent += incre;
		if (indent < 0) {
			indent = 1;
			incre = 1;
		}
		while (r > -1) {
			if (0 <= r && r < N && 0 <= (i - r) && (i - r) < M) {
				tmp.push_back(mat[r][i - r]);
				tmp.push_back(' ');
			}
			r--;
		}
		tmp.pop_back();
		res.push_back(tmp);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> R >> C;
	arr.resize(R);
	rep(i, 0, R)
		arr[i].resize(C);
	rep(i, 0, R)
		rep(j, 0, C)
		cin >> arr[i][j];
	cin >> num;
	rep(i, 0, num / 90)
		arr = rotate90(arr);
	if (num % 90)
		arr = rotate45(arr);
	rep(i, 0, arr.size()) {
		rep(j, 0, arr[i].size()) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}