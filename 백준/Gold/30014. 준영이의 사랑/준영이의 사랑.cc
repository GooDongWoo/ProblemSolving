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

int n, ps[2000];
int main() {
	fastio;
	cin >> n;
	rep(i, 0, n) cin >> ps[i];
	sort(ps, ps + n, greater<int>());
	deque<int> dq;
	dq.push_back(ps[0]);
	bool flag = 1;
	rep(i, 1, n) {
		if (flag) {
			dq.push_front(ps[i]);
			flag ^= 1;
		}
		else {
			dq.push_back(ps[i]);
			flag ^= 1;
		}
	}
	int res = 0,idx = 0;
	for (const auto& x : dq) ps[idx++] = x;
	rep(i, 0, n) res += ps[(i + n) % n] * ps[(i - 1 + n) % n];

	printf("%d\n", res);
	rep(i, 0, n) printf("%d ", ps[i]);

	return 0;
}