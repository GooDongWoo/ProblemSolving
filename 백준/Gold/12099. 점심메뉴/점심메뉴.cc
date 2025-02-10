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
int N, Q;
pair <int, int>arr[MAX];

int (*fs[2])(int) {
	[](int a) {return arr[a].fi;},
	[](int a) {return arr[a].se;}
};

int lbs(int target,int sel, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (target <= fs[sel](mid)) end = mid - 1;
		else start = mid + 1;
	}
	return start;
}

int ubs(int target, int sel, int start, int end) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (target < fs[sel](mid)) end = mid - 1;
		else start = mid + 1;
	}
	return start;
}

int main() {
	fastio;
	cin >> N >> Q;
	rep(i, 0, N)cin >> arr[i].fi >> arr[i].se;
	sort(arr, arr + N);

	int u, v, x, y;
	rep(i, 0, Q) {
		cin >> u >> v >> x >> y;
		int minis = lbs(u, 0, 0, N - 1);
		int e = ubs(v, 0, 0, N - 1);
		int cnt = 0;
		rep(j, minis, e) {
			if (x <= arr[j].se && arr[j].se <= y) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}