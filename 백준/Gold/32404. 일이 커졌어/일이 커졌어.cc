#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int N, arr[101];

int main() {
	fastio;
	cin >> N;
	int MAX = N;
	int idx = N;
	if (!(idx & 1)) {
		idx--;
	}
	while (idx > 0) {// 홀수번째 큰 -> 작은
		arr[idx] = MAX;
		MAX--;
		idx -= 2;
	}
	//짝수 작은 -> 큰
	for (int i = 2; i < N + 1; i += 2) {
		arr[i] = MAX;
		MAX--;
	}
	rep(i, 1, N + 1) {
		printf("%d ", arr[i]);
	}
}