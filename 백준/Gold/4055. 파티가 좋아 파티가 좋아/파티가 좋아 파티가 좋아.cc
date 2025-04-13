#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

int P, ans, s, e, day;

int main() {
	fastio;
	day = 1;
	while (1) {
		cin >> P;
		if (P == 0)
			break;
		vector<pair<int, int>> arr;
		rep(i, 0, P) {
			cin >> s >> e;
			arr.push_back({ s * 2,e * 2 });
		}
		sort(arr.begin(), arr.end());
		priority_queue<int, vector<int>, greater<>> pq;
		ans = 0;
		int idx = 0;
		rep(ct, 16, 48 + 1) {
			while (idx < P && arr[idx].first == ct) {
				pq.push(arr[idx++].second);
			}
			while (pq.size() && pq.top() <= ct) {
				pq.pop();
			}
			if (pq.size()) {
				pq.pop();
				ans++;
			}
		}
		printf("On day %d Emma can attend as many as %d parties.\n", day++, ans);
	}
	return 0;
}