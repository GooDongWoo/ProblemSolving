#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

LL T, N,tmp;

int main() {
	fastio;
	cin >> T;
	rep(test_case, 1, T + 1) {
		cin >> N;
		tmp = 0;
		rep(i, 0, N) {
			LL a;
			cin >> a;
			tmp = (tmp + a) % N;
		}
		if (tmp % N == 0) printf("YES\n");
		else printf("NO\n");
	}
}