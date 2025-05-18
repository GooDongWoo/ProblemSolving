#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[2250000];

int main() {
	fastio;
	cin >> N;
	rep(i, 0, N * N)
		cin >> arr[i];
	sort(arr, arr + (N * N), greater<>());
	printf("%d\n", arr[N - 1]);
	return 0;
}