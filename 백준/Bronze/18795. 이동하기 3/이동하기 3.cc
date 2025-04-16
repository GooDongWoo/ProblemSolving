#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

#define rep(i,a,b) for(int i=a;i<b;++i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define LL long long

using namespace std;

#define LIMIT 500000

int N, M;
LL ans;


int main() {
	fastio;
	cin >> N >> M;
	int tmp;
	rep(i, 0, N) {
		cin >> tmp;
		ans += tmp;
	}
	rep(i, 0, M) {
		cin >> tmp;
		ans += tmp;
	}
	printf("%lld\n", ans);
}