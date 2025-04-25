#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, arr[200000], tq[200000][2], incre;
LL ans;

int main() {
	fastio;
	cin >> N >> M;
	rep(i, 0, N)
		cin >> arr[i];
	rep(i, 0, M)
		cin >> tq[i][0] >> tq[i][1];
	sort(arr, arr + N, greater<>());
	int useidx = 0;
	rep(i, 0, M) {
		int incre = tq[i][0];
		int thres = tq[i][1];
		while (ans < thres && useidx < N)
			ans += (arr[useidx++] + incre);
		if (ans < thres) {
			printf("-1\n");
			return 0;
		}
		if (i == M - 1) {
			while (useidx < N)
				ans += (arr[useidx++] + incre);
		}
	}
	printf("%lld\n", ans);
	return 0;
}