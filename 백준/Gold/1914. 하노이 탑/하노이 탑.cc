#include <iostream>
#include <algorithm>
#include <string>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N;
string ans;

string sF(string num) {
	string ret,rret;
	int nsize = num.size();
	int carry = 0;
	rep(i, 0, nsize) {
		int cval = num[nsize - 1 - i] - '0';
		cval = 2 * cval + carry;
		carry = (cval > 9) ? 1 : 0;
		cval %= 10;
		ret = to_string(cval) + ret;
	}
	if (carry) {
		ret = "1" + ret;
	}

	nsize = ret.size();
	carry = 0;
	rep(i, 0, nsize) {
		int cval = ret[nsize - 1 - i] - '0';
		if (i == 0) {
			cval++;
		}
		cval = cval + carry;
		carry = (cval > 9) ? 1 : 0;
		cval %= 10;
		rret = to_string(cval) + rret;
	}
	if (carry) {
		rret = "1" + rret;
	}
	return rret;
}

void F(int start, int end, int depth) {
	int left = 6 - start - end;
	if (depth == 1) {
		cout << start << ' ' << end << '\n';
		return;
	}
	F(start, left, depth - 1);
	cout << start << ' ' << end << '\n';
	F(left, end, depth - 1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	ans = "1";
	rep(i, 1, N) {
		ans = sF(ans);
	}
	cout << ans << '\n';
	if (N <= 20) {
		F(1, 3, N);
	}
	return 0;
}