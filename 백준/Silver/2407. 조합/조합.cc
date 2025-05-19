#define rep(i,a,b) for(int i=a;i<b;++i)

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N, M;
string dp[101][101];

string cal(string a, string b) {
	string res;
	int alen, blen;
	alen = a.size();
	blen = b.size();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (alen > blen) {
		rep(i, 0, alen - blen)
			b += "0";
	}
	else {
		rep(i, 0, blen - alen)
			a += "0";
	}
	int carry = 0;
	rep(i, 0, max(alen, blen)) {
		int anum = a[i] - '0';
		int bnum = b[i] - '0';
		int tnum = anum + bnum + carry;
		carry = tnum / 10;
		int val = tnum % 10;
		res.push_back('0' + val);
	}
	if(carry)
		res.push_back('1');
	reverse(res.begin(), res.end());
	return res;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	rep(i, 1, 101) {
		dp[i][0] = "1";
		dp[i][i] = "1";
	}
	rep(i, 2, 101) {
		rep(j, 1, i) {
			dp[i][j] = cal(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}
	cin >> N >> M;
	printf("%s\n", dp[N][M].c_str());
	return 0;
}