#include <iostream>
#include <algorithm>
#include <string>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N;
string a, b, pattern;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> b;
	N = a.size();

	rep(i, 0, N) {
		pattern += ((b[i] - a[i] + 25) % 26) + 'A';
	}

	rep(i, 1, N + 1) {
		if (N % i != 0) {
			continue;
		}
		string subs = pattern.substr(0, i);
		string tmp;
		rep(j, 0, N / i) {
			tmp += subs;
		}
		if (tmp == pattern) {
			cout << subs;
			return 0;
		}
	}
	return 0;
}