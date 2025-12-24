#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

int N;
string word = "1";
bool isFind;

bool chck(int val) {
	word.push_back(val + '0');
	bool ret = true;
	int sz = word.size();
	int cmpNum = 1;
	while (2 * cmpNum <= sz) {
		if (word.substr(sz - cmpNum - cmpNum, cmpNum) == word.substr(sz - cmpNum, cmpNum)) {
			ret = false;
			break;
		}
		cmpNum++;
	}
	word.pop_back();
	return ret;
}

void bt(int idx) {
	if (idx >= N) {
		isFind = true;
		cout << word;
		return;
	}
	rep(nxt, 1, 4) {
		if (!chck(nxt)) continue;
		word.push_back(nxt + '0');
		bt(idx + 1);
		word.pop_back();
		if (isFind) {
			return;
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	bt(1);
	return 0;
}