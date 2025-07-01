#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	fastio;
	int N;
	queue<int> q;
	cin >> N;
	rep(i, 1, N + 1) {
		q.push(i);
	}
	while (q.size()) {
		int f = q.front(); q.pop();
		printf("%d ", f);
		if (q.size() == 0) {
			break;
		}
		f = q.front();
		q.pop();
		q.push(f);
	}
	return 0;
}