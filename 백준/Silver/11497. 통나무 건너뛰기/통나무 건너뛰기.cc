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
#include <unordered_map>
#include <set>
#include <cmath>
#include <cstring>

using namespace std;

int T, N, arr[10000],ans;

int main() {
	fastio;
	cin >> T;
	rep(test_case, 0, T) {
		ans = 0;
		cin >> N;
		rep(i, 0, N) {
			cin >> arr[i];
		}
		sort(arr, arr + N);
		deque<int> dq;
		dq.push_back(arr[0]);
		bool fb = 1;
		rep(i, 1, N) {
			int cmpnd;
			if (fb) {
				cmpnd = dq.back();
				ans = max(ans, abs(cmpnd - arr[i]));
				dq.push_back(arr[i]);
			}
			else {
				cmpnd = dq.front();
				ans = max(ans, abs(cmpnd - arr[i]));
				dq.push_front(arr[i]);
			}
			fb ^= 1;
		}
		ans = max(ans,abs(dq.back() - dq.front()));
		printf("%d\n", ans);
	}
}