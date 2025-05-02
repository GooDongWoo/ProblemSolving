#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cstring>

using namespace std;

#define MOD 1000000009

int N;
LL ans=0;

int main() {
	fastio;
	cin >> N;
	if (N >= 2)
		ans = 2;
	for (int i = 3;i <= N;++i) {
		ans = (ans * 3) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}