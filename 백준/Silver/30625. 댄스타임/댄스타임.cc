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

int N, M, a, b;
LL ans[2];
const LL MOD = 1e9 + 7;

int main() {
	fastio;
	cin >> N >> M;
	cin >> a >> b;
	if (b == 0) {
		ans[0] = 1;
		ans[1] = M - 1;
	}
	else {
		ans[0] = M - 1;
		ans[1] = 1;
	}
	rep(i, 1, N) {
		cin >> a >> b;
		if (b != 0) {//뒷춤-> (M-1)다른 춤 춰야함
			ans[1] = (ans[0] + (ans[1] * (M - 1))%MOD)%MOD;//이번에 처음 틀림 + (1번틀림+이번 맞음)
			ans[0] = (ans[0] * (M - 1)) % MOD;// 이번 맞음
			
		}
		else {//앞춤-> 같은 춤 춰야함
			ans[1] = ((ans[0] * (M - 1)) % MOD + ans[1]) % MOD;//이번에 처음 틀림 + (1번틀림+이번 맞음)
			ans[0];//이번 맞음
		}
	}
	printf("%lld", (ans[0] + ans[1]) % MOD);
	return 0;
}