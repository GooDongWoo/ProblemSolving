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

int N, F, arr[10][10], chck[11], Flag = 1;
void bt(int idx) {
	if (idx == N) {
		rep(i, 1, N) {
			rep(j, 0, N - i) {
				arr[i][j] = arr[i - 1][j] + arr[i - 1][j + 1];
			}
		}
		if (arr[N - 1][0] == F && Flag) {
			rep(i, 0, N)
				printf("%d ", arr[0][i]);
			printf("\n");
			Flag = 0;
		}
	}
	else {
		rep(i, 1, N + 1) {
			if (chck[i])
				continue;
			chck[i] = 1;
			arr[0][idx] = i;
			bt(idx + 1);
			chck[i] = 0;
			if (Flag == 0)
				return;
		}
	}
}

int main() {
	fastio;
	cin >> N >> F;
	bt(0);

	return 0;
}