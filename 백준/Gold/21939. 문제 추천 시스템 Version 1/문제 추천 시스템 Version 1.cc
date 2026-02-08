#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <unordered_map>
#include <cmath>
#include <string>
#include <cstring>
#include <stdexcept>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;
using LL = long long;
using UI = unsigned int;

int N, M, ans[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minq;
priority_queue<pair<int, int>> maxq;


int main() {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N;
	rep(i, 0, N) {
		int p, l;
		cin >> p >> l;
		ans[p] = l;
		minq.push({ l,p });
		maxq.push({ l,p });
	}
	cin >> M;
	rep(i, 0, M) {
		string cmd;
		cin >> cmd;
		if (cmd == "add") {
			int p, l;
			cin >> p >> l;
			ans[p] = l;
			minq.push({ l,p });
			maxq.push({ l,p });
		}
		else if (cmd == "solved") {
			int p;
			cin >> p;
			ans[p] = 0;
		}
		else {
			int what;
			cin >> what;
			if (what == 1) {
				while (true) {
					if (maxq.size()) {
						if (ans[maxq.top().second] == maxq.top().first) {
							cout << maxq.top().second<<'\n';
							break;
						}
						else {
							maxq.pop();
						}
					}
					else {
						throw runtime_error(" wrong scenario: empty maxq");
					}
				}
			}
			else {
				while (true) {
					if (minq.size()) {
						if (ans[minq.top().second] == minq.top().first) {
							cout << minq.top().second << '\n';
							break;
						}
						else {
							minq.pop();
						}
					}
					else {
						throw runtime_error(" wrong scenario: empty minq");
					}
				}
			}
		}
	}
	return 0;
}