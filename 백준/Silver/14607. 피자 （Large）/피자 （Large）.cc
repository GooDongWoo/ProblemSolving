#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

int N;
unordered_map<LL, LL> dict;
LL ans;

void cal(LL num) {
	if (dict.find(num) != dict.end())
		return;
	LL nxt = num / 2;
	LL cur = nxt * (num - nxt);
	cal(nxt); cal(num - nxt);
	dict[num] = cur + dict[nxt] + dict[num - nxt];
	return;
}

int main() {
	fastio;
	cin >> N;
	dict[1] = 0; dict[0] = 0;
	cal(N);
	printf("%lld\n", dict[N]);
	return 0;
}