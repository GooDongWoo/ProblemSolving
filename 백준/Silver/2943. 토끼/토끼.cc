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

LL N, M, boxes[100001], cups[320], ans;;

int main() {
	fastio;
	cin >> N >> M;
	LL K = (LL)sqrt(N);
	LL start, num, lcnt, rcnt, end, bef_end;
	rep(i, 0, M) {
		ans = 0;
		cin >> num >> start;
		bef_end = start - 1;
		end = bef_end + num;
		if (num >= K) {
			lcnt = (K - (bef_end % K)) % K;
			rep(j, 0, lcnt) ans += ++boxes[start + j];
			if (end == N) {
				rcnt = N % K;
				if (rcnt) ans += (++cups[K+1]);
			}
			else {
				rcnt = (end) % K;
				rep(j, 0, rcnt) ans += ++boxes[end - j];
			}
			num -= (lcnt + rcnt);
			rep(j, 0, num / K) ans += (++cups[(start + lcnt) / K + j]);
		}
		else {
			rep(j, 0, num) ans += ++boxes[start + j];
		}
		printf("%lld\n", ans);
	}
	return 0;
}