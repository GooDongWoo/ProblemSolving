#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

const int MOD = 1000000;
int dp[5001];
string word;
bool isPossible = true;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> word;
	dp[0] = 1;
	rep(i, 0, word.size()) {
		//1글자이면 0은 안됨
		if (word[i] != '0') {
			dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
		}
		//2글자이면 
		//첫글자가 0이면 안됨,
		//그리고 26을 초과하면 안됨;
		if (i > 0 && word[i - 1] != '0') {
			int tmp = (word[i - 1] - '0') * 10 + (word[i] - '0');
			if (0 < tmp && tmp < 27) {
				dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
			}
		}
	}
	cout << dp[word.size()];
}