#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

const int MAX = 200001;
const LL MOD = 1e9 + 7;

template <class T>
class BIT {
public:
	T bit[MAX]{};
	void update(int idx, T val) {
		while (idx <= MAX - 1) {
			bit[idx] += val;
			idx += idx & -idx;
		}
		return;
	}

	T query(int idx) {
		T ret = 0;
		while (idx > 0) {
			ret += bit[idx];
			idx -= idx & -idx;
		}
		return ret;
	}
};

int N;
LL ans = 1;
BIT<LL> ValBit;
BIT<LL> NumBit;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	int x;
	cin >> x; x++;
	ValBit.update(x, x);
	NumBit.update(x, 1);

	rep(i, 1, N) {
		cin >> x; x++;
		LL cur = 0;
		LL ValOne2X = ValBit.query(x);
		LL NumOne2X = NumBit.query(x);
		cur += (x * NumOne2X) - ValOne2X;
		cur %= MOD;

		LL ValOne2MAX = ValBit.query(MAX - 1);
		LL NumOne2MAX = NumBit.query(MAX - 1);
		cur += (ValOne2MAX - ValOne2X) - (x * (NumOne2MAX - NumOne2X));
		cur %= MOD;

		ValBit.update(x, x);
		NumBit.update(x, 1);
		ans = (ans * cur) % MOD;
	}
	cout << ans;

	return 0;
}