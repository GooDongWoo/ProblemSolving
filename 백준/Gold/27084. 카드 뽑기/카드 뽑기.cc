#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#define LL long long
#define rep(i,a,b) for(int i=a;i<b;++i)
using namespace std;

const LL MOD = 1e9 + 7;
LL N, ans = 1;

unordered_map<int, int> dict;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	rep(i, 0, N) {
		int a;
		cin >> a;
		dict[a]++;
	}
	for (const auto& x : dict) {
		LL val = x.second;
		ans = (ans * (val + 1)) % MOD;
	}
	ans = (MOD + ans - 1) % MOD;
	cout << ans;
	return 0;
}