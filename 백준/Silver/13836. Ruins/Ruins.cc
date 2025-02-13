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

int main() {
	fastio;
	int a, b;
	double min1;
	while (1) {
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		vector <int> arr[2];
		min1 = 1e9;
		rep(i, 1, pow(a, .5) + 1) if (a % i == 0)arr[0].push_back(i);
		rep(i, 1, pow(b, .5) + 1) if (b % i == 0)arr[1].push_back(i);
		int tmp[4];
		rep(i, 0, arr[0].size()) {
			rep(j, 0, arr[1].size()) {
				tmp[0] = arr[0][i];
				tmp[1] = a / tmp[0];
				tmp[2] = arr[1][j];
				tmp[3] = b / tmp[2];
				sort(tmp, tmp + 4);
				min1 = min(min1, pow(tmp[1] - tmp[0], 2) + pow(tmp[2] - tmp[1], 2) + pow(tmp[3] - tmp[2], 2));
			}
		}
		printf("%d\n", (int)min1);
	}
	return 0;
}