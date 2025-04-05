#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

int N, arr[16][16], cnt1, cnt2, dp[16][16];


int matrix_path_rec(int i, int j) {
	if (i == 0 or j == 0) {
		cnt1++;
		return 0;
	}
	else
		return (arr[i][j] + (max(matrix_path_rec(i - 1, j), matrix_path_rec(i, j - 1))));
}

int matrix_path1(int n) {
	return matrix_path_rec(n, n);
}

int matrix_path2(int n) {
	rep(i, 1, n+1)
		rep(j, 1, n+1) {
		dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
		cnt2++;
	}
	return dp[n][n];
}
int main() {
	fastio;
	cin >> N;
	rep(i, 1, N + 1)
		rep(j, 1, N + 1)
		cin >> arr[i][j];
	matrix_path1(N);
	matrix_path2(N);
	printf("%d %d", cnt1, cnt2);
	return 0;
}