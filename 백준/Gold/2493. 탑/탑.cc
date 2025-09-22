#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int N, arr[500001], ans[500001];;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	rep(i, 1, N + 1) {
		cin >> arr[i];
	}

	rep(i, 0, N) {
		while (pq.size() && arr[N - i] > pq.top().first) {
			ans[pq.top().second] = N - i;
			pq.pop();
		}
		pq.push({ arr[N - i] ,N - i });
	}
	rep(i, 1, N + 1) {
		cout << ans[i]<<' ';
	}
	return 0;
}