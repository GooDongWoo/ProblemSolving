#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
using LL = long long;
#define rep(i,a,b) for(int i=a;i<b;++i)

int T, N;

int main() {
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	rep(test_case, 0, T) {
		priority_queue<LL, vector<LL>, greater<>> pq;
		cin >> N;
		rep(i, 0, N) {
			LL tmp;
			cin >> tmp;
			pq.push(tmp);
		}
		LL ans = 0;
		while (pq.size() > 1) {
			LL val1 = pq.top(); pq.pop();
			LL val2 = pq.top(); pq.pop();
			ans += val1 + val2;
			pq.push(val1 + val2);
		}
		cout << ans << '\n';
	}
	return 0;
}
