#include <iostream>
#include <algorithm>
#include <queue>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int N;
priority_queue<int, vector<int>, greater<>> sq;
priority_queue<int, vector<int>, less<>> bq;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> N;
	rep(i, 1, N + 1) {
		int inp;
		cin >> inp;
		bq.push(inp);
		int btop = bq.top();
		bq.pop();
		sq.push(btop);
		if (i & 1) {
			int stop = sq.top();
			sq.pop();
			bq.push(stop);
		}
		cout << bq.top()<<'\n';
	}
	return 0;
}