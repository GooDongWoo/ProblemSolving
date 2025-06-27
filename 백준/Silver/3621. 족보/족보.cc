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

int N, D, cnter[100001];
LL ans;

int main() {
	fastio;
	cin >> N >> D;
	int a;
	rep(i, 0, N) {
		cin >> a;
		cnter[a]++;
	}
	rep(i, 0, N + 1) {
		int num = cnter[i];
		while (num > D) {
			int div = num / D;
			int mod = num % D;
			ans += div;
			num = div + mod;
		}
	}
	printf("%lld\n", ans);
}