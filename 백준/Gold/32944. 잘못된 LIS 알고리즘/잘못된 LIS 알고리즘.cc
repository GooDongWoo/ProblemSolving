#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int N, M, K;
deque<int> dq;
vector<int> arr;

int main() {
	fastio;
	cin >> N >> M >> K;
	if (M == N) {
		printf("-1");
	}
	else {
		arr.resize(K);
		rep(i, 1, K)
			arr[i - 1] = i;
		arr[K - 1] = N;

		rep(i, K, N)
			dq.push_back(i);

		vector<int> tmp;
		rep(i, 0, M - K + 1) {
			tmp.push_back(dq.back());
			dq.pop_back();
		}
		sort(tmp.begin(), tmp.end());
		for (const int& x : tmp) {
			arr.push_back(x);
		}
		while (dq.size()) {
			arr.push_back(dq.back());
			dq.pop_back();
		}
		for (const int& x : arr) {
			printf("%d ", x);
		}
	}
}