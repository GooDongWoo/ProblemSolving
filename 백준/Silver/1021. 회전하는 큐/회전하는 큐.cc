#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N, M, ans;
deque<int> dq;

int main() {
	fastio;
	cin >> N >> M;
	rep(i, 1, N + 1)
		dq.push_back(i);
	rep(i, 0, M) {
		int a;
		cin >> a;
		int dqSize = dq.size();
		int cnter = 0;
		while (dq.front() != a) {
			int f = dq.front();
			dq.pop_front();
			dq.push_back(f);
			cnter++;
		}
		dq.pop_front();
		ans += min(cnter, dqSize - cnter);
	}
	printf("%d\n", ans);
	return 0;
}