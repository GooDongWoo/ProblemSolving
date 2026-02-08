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

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;
using LL = long long;
using UI = unsigned int;

int T, K;

int main() {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> T;
	rep(test_case, 0, T) {
		priority_queue<int> maxq;
		priority_queue<int, vector<int>, greater<>> minq;
		unordered_map<int, int> dict;

		cin >> K;
		dict.reserve(K);

		rep(mini, 0, K) {
			char cmd;
			int val;
			cin >> cmd >> val;
			switch (cmd) {
			case('I'):
				maxq.push(val);
				minq.push(val);
				dict[val]++;
				break;
			case('D'):
				if (val == 1) {
					while (1) {
						if (maxq.size()) {
							int cur = maxq.top();
							maxq.pop();
							if (dict[cur] > 0) {
								dict[cur]--;
								break;
							}
						}
						else {
							break;
						}
					}
				}
				else {// val == -1
					while (1) {
						if (minq.size()) {
							int cur = minq.top();
							minq.pop();
							if (dict[cur] > 0) {
								dict[cur]--;
								break;
							}
						}
						else {
							break;
						}
					}
				}
				break;
			}
		}
		while (maxq.size() && dict[maxq.top()] <= 0) {
			maxq.pop();
		}
		if (maxq.size() == 0) {
			cout << "EMPTY\n";
			continue;
		}
		while (minq.size() && dict[minq.top()] <= 0) {
			minq.pop();
		}
		cout << maxq.top() << ' ' << minq.top() << '\n';
	}
	return 0;
}