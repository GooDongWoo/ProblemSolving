#include <iostream>
#include <algorithm>
#include <string>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int ff[1000000], maxCnter;
string word;

void makeff() {
	int cnt = 0;
	rep(cur, 1, word.size()) {
		while (cnt > 0 && word[cur] != word[cnt]) {
			cnt = ff[cnt - 1];
		}
		if (word[cur] == word[cnt]) {
			ff[cur] = ++cnt;
		}
		if (cur != word.size() - 1) {
			maxCnter = max(maxCnter, ff[cur]);
		}
	}
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> word;
	makeff();
	int cnt = ff[word.size() - 1];
	while (maxCnter < cnt) {
		cnt = ff[cnt - 1];
	}
	if (cnt == 0) {
		cout << -1;
	}
	else {
		rep(i, 0, cnt) {
			cout << word[i];
		}
	}
	return 0;
}