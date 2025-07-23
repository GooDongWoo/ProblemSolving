#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

#define rep(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;

int N, K;
set<int> los;
map<int, int> dict;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	rep(i, 1, N + 1) {
		los.insert(i);
	}
	rep(i, 0, N) {
		int a;
		cin >> a;
		if (los.count(a) > 0) {
			los.erase(a);
		}
		else {
			dict[a]++;
		}
	}

	for (int x : los) {
		int cnt = 0;
		for (auto cp : dict) {
			cnt++;
			int y = cp.first;
			if ((x > y) && ((x - y) % K == 0)) {
				dict[y]--;
				if (dict[y] < 1) {
					dict.erase(y);
				}
				break;
			}
			if (cnt == dict.size()) {
				cout << 0;
				return 0;
			}
		}
	}
	cout << 1;
	return 0;
}