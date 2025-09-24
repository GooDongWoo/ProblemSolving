#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int N, M, ans;
unordered_set<int> s1;

bool chck(int num) {
	do{
		if (s1.count(num % 10)) {
			return false;
		}
		num /= 10;
	} while (num);
	return true;
}

int GetNumLen(int num) {
	int ret = 0;
	do{
		ret++;
		num /= 10;
	} while (num);
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> N;
	cin >> M;
	rep(i, 0, M) {
		int a;
		cin >> a;
		s1.insert(a);
	}
	ans = abs(100 - N);
	rep(i, 0, 900000) {
		int cost = GetNumLen(i);
		if (chck(i)) {
			ans = min(ans, cost + abs(N - i));
		}
	}
	cout << ans;
	return 0;
}