#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>

#define rep(i, a, b) for (int i=a;i<b;++i)
using LL = long long;
using namespace std;

int N, S, M, arr[50];
set<int> s1, s2;

bool chck(int num) {
	return (0 <= num && num <= M);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N >> S >> M;
	rep(i, 0, N) {
		cin >> arr[i];
	}
	s1.insert(S);
	rep(i, 0, N) {
		for (const int& val : s1) {
			if (chck(val - arr[i])) {
				s2.insert(val - arr[i]);
			}
			if (chck(val + arr[i])) {
				s2.insert(val + arr[i]);
			}
		}
		s1.swap(s2);
		s2.clear();
	}
	if (s1.size())
		cout << *s1.rbegin();
	else
		cout << -1;
	return 0;
}