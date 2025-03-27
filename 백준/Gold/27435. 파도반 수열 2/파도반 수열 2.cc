#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define LL long long
using namespace std;
const LL MOD = 998244353;
int T;
LL N, arr[5] = { 1,1,1,2,2 };
vector<vector<LL>> bmat(5, vector<LL>(5, 0));

vector<vector<LL>> matmul(const vector<vector<LL>>& m1, const vector<vector<LL>>& m2) {
	vector<vector<LL>> res(5, vector<LL>(5, 0));
	rep(i, 0, 5)
		rep(j, 0, 5)
		rep(steps, 0, 5)
		res[i][j] = (res[i][j] + m1[i][steps] * m2[steps][j]) % MOD;
	return res;
}

vector<vector<LL>> recursive(LL num) {
	if (num <= 1)
		return bmat;
	vector<vector<LL>> tmp = recursive(num / 2);
	tmp = matmul(tmp, tmp);
	if (num & 1) {
		return matmul(tmp, bmat);
	}
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bmat =
	{ {1,0,0,0,1},
	  {1,0,0,0,0},
	  {0,1,0,0,0},
	  {0,0,1,0,0},
	  {0,0,0,1,0} };
	cin >> T;
	rep(t, 0, T) {
		cin >> N;
		if (N < 6) {
			printf("%lld\n", arr[N - 1]);
			continue;
		}
		vector<vector<LL>> tmp = recursive(N-1);
		LL ans = 0;
		rep(i, 0, 5)
			ans = (ans + tmp[4][i] * arr[4 - i]) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}