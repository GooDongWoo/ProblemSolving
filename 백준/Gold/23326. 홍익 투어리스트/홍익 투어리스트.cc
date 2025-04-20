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
#include <set>

using namespace std;

int N, Q, cmd, val, cur;
set<int> s1;

int main() {
	fastio;
	cin >> N >> Q;
	rep(i, 0, N) {
		cin >> cmd;
		if (cmd == 1)
			s1.insert(i);
	}

	rep(i, 0, Q) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> val; val--;
			if (s1.find(val) == s1.end())
				s1.insert(val);
			else
				s1.erase(val);
		}
		else if (cmd == 2) {
			cin >> val;
			cur = (cur + val) % N;
		}
		else {
			if (s1.size() == 0) {
				printf("-1\n");
				continue;
			}
			auto itr = s1.lower_bound(cur);
			if (itr == s1.end()) {// 첫번째로 가야함.
				printf("%d\n", ((*s1.begin()) - cur + N) % N);
			}
			else {// 거기까지 가면됨.
				printf("%d\n", (*itr) - cur);
			}
		}
	}
	return 0;
}