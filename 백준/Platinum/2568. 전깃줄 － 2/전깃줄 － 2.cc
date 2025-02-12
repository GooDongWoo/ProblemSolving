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

#define MAX 100000

typedef struct Point {
	int a, b;
	bool operator < (Point other) {
		return b < other.b;
	}
};

int N, idxmemo[MAX], dp[MAX];
Point arr[MAX];

int lb(int target) {
	int start = 0, end = MAX - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (target < dp[mid]) { end = mid - 1; }
		else { start = mid + 1; }
	}
	return start;
}

int main() {
	fastio;
	cin >> N;
	rep(i, 0, N) cin >> arr[i].a >> arr[i].b;
	sort(arr, arr + N);
	rep(i, 0, MAX) dp[i] = 1e9;
	int midx = 0;
	rep(i, 0, N) {
		int target = arr[i].a;
		int tidx = lb(target);
		midx = max(midx, tidx);
		dp[tidx] = target;
		idxmemo[i] = tidx;
	}
	printf("%d\n", N - midx-1);
	vector <int> ans;
	int idx = N - 1;
	while (idx > -1) {
		if (idxmemo[idx] == midx) {
			midx--;
		}
		else ans.push_back(arr[idx].a);
		idx--;
	}
	sort(ans.begin(), ans.end());
	for (const int& item : ans) {
		printf("%d\n",item);
	}


	return 0;
}