#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)

#include <iostream>

using namespace std;

int N, K, arr[200000], psum[200001],max1;

int main() {
	fastio;
	cin >> N >> K;
	rep(i, 0, N) {
		cin >> arr[i];
		arr[N + i] = arr[i];
	}
	rep(i, 1, 2 * N + 1) psum[i] = psum[i - 1] + arr[i];
	rep(i, 0, N) max1 = max(max1, psum[i + K] - psum[i]);
	printf("%d\n", max1);
	return 0;
}