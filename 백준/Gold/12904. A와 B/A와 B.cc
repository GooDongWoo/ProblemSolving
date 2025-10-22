#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

string a, b;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> a >> b;
	while (b.size() != a.size()) {
		if (b.back() == 'A') {
			b.pop_back();
		}
		else {
			b.pop_back();
			reverse(b.begin(), b.end());
		}
	}
	cout << ((a == b) ? "1" : "0");
	return 0;
}