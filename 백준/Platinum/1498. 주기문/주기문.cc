#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

int ff[1000000];
string word;

void makePI() {
	int cnt = 0;
	rep(cur, 1, word.size()) {
		while (cnt > 0 && word[cur] != word[cnt]) {
			cnt = ff[cnt - 1];
		}
		if (word[cur] == word[cnt]) {
			ff[cur] = ++cnt;
		}
		int len = cur + 1;
		if ((cnt >= len / 2) && (cnt % (len - cnt) == 0)) {
			cout << len << ' ' << len / (len - cnt) << '\n';
		}
	}
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	memset(ff, 0, sizeof(ff));
	cin >> word;
	makePI();
	return 0;
}