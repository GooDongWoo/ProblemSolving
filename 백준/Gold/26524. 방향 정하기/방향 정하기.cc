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

LL N, ans = 1;
const int MOD = 1e9 + 7;

int main() {
	fastio;
	cin >> N;
	rep(i, 2, N + 1) ans = (ans * i) % MOD;
	printf("%lld\n", ans);
}