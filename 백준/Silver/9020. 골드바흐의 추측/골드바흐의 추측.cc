#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>
#include <set>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int N;
bool arr[10001];
set<int> s1;

int main() {
	ios_base::sync_with_stdio(false);
	rep(i, 2, 10000) {
		if (!arr[i]) {
			s1.insert(i);
			for (int j = i * i; j < 10001; j += i) {
				arr[j] = 1;
			}
		}
	}
	cin >> N;
	rep(i, 0, N) {
		int a;
		cin >> a;
		int v1 = 0;
		for (const int& x : s1) {
			if (x > (a / 2)) {
				break;
			}
			if (s1.count(a - x)) {
				v1 = x;
			}
		}
		cout << v1 << ' ' << a - v1 << '\n';
	}
	return 0;
}