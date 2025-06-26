#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int N, D, tmp;
map<int, int> dict;
LL ans;

int main() {
	fastio;
	cin >> N >> D;
	rep(i, 0, N) {
		cin >> tmp;
		dict[tmp]++;
	}
	rep(i, 0, D) {
		auto x = dict.rbegin();
		int idx = x->first;
		int cnter = x->second;
		if (idx == 0) {
			break;
		}
		ans += x->second;
		dict[idx - 1] += x->second;
		dict.erase(idx);
	}
	printf("%lld\n", ans);
}