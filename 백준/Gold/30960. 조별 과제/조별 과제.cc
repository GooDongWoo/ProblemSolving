#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, arr[500000], lsum[500000], rsum[500000], ans;

int main() {
	fastio;
	ans = 1e9;
	cin >> N;
	rep(i, 0, N)
		cin >> arr[i];
	sort(arr, arr + N);
	lsum[2] = arr[1] - arr[0];
	rsum[N - 3] = arr[N - 1] - arr[N - 2];
	for (int i = 4; i < N; i += 2) {
		lsum[i] = lsum[i - 2] + arr[i - 1] - arr[i - 2];
		rsum[N - 1 - i] = rsum[N - 1 - i + 2] + arr[N - 1 - i + 2] - arr[N - 1 - i + 1];
	}
	for (int i = 0; i < N-1; i += 2) 
		ans = min(ans, lsum[i] + (arr[i + 2] - arr[i]) + rsum[i + 2]);
	printf("%d\n", ans);
	return 0;
}