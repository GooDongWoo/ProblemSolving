#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N;
LL ans;

int main() {
	fastio;
	cin >> N;
	int cur;
	stack<pair<int, int>> stck;
	rep(i, 0, N) {
		cin >> cur;
		if (stck.size()) {
			if (stck.top().first > cur) {
				ans++;
				stck.push({ cur ,1 });
			}
			else {
				while (stck.size() && stck.top().first < cur) {
					ans += stck.top().second;
					stck.pop();
				}
				int same_cnt = 0;
				if (stck.size() && stck.top().first == cur) {
					same_cnt = stck.top().second;
					ans += same_cnt;
					stck.pop();
				}
				if (stck.size())
					ans++;
				stck.push({ cur ,same_cnt + 1 });
			}
		}
		else {
			stck.push({ cur,1 });
		}
	}
	printf("%lld\n", ans);
	return 0;
}