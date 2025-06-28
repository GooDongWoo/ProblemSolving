#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;

int N, K, ans[300000];
priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> pq;


int main() {
	fastio;
	cin >> N >> K;
	int cnt;
	rep(idx, 1, K + 1) {
		cin >> cnt;
		pq.push({ cnt,idx });
	}
	auto curp = pq.top(); pq.pop();
	ans[0] = curp.second;
	if (curp.first - 1 > 0) {
		pq.push({ curp.first - 1,curp.second });
	}
	rep(i, 1, N) {
		auto curp = pq.top(); pq.pop();
		if (ans[i - 1] == curp.second) {
			if (pq.size()) {
				auto befp = pq.top(); pq.pop();
				ans[i] = befp.second;
				if (befp.first - 1 > 0) {
					pq.push({ befp.first - 1,befp.second });
				}
				pq.push(curp);
			}
			else {
				printf("-1\n");
				return 0;
			}
		}
		else {
			ans[i] = curp.second;
			if (curp.first - 1 > 0) {
				pq.push({ curp.first - 1,curp.second });
			}
		}
	}

	rep(i, 0, N) {
		printf("%d ", ans[i]);
	}
}