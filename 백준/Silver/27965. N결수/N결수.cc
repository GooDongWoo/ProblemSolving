#define _CRT_SECURE_NO_WARNINGS
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
#include <map>
#include <set>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

int N, K;
LL cur;
string scur;

int main() {
	fastio;
	cin >> N >> K;
	cur = 1;
	rep(i, 2, N + 1) {
		scur = to_string(i);
		int length = scur.size();
		cur = ((cur * ((LL)pow(10, length))) % K + i) % K;
	}
	printf("%lld", cur % K);
	return 0;
}