#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int K, N, arr[100], cnter = 1;
priority_queue<LL, vector<LL>, greater<>>pq;
LL LIMIT = (1LL << 31);

int main() {
	fastio;
	cin >> K >> N;
	rep(i, 0, K) {
		cin >> arr[i];
		pq.push(arr[i]);
	}
	while (cnter < N) {
		LL cur = pq.top();
		pq.pop();
		int j = K - 1;
		while ((cur % arr[j]) != 0) {
			j--;
		}
		rep(i, j, K) {
			LL cand = arr[i] * cur;
			if (cand > LIMIT) {
				break;
			}
			pq.push(cand);
		}
		cnter++;
	}
	cout << pq.top();
	return 0;
}