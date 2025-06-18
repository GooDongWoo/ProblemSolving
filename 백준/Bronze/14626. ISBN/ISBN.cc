#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
	fastio;
	string word;
	cin >> word;
	int idx = 0;
	rep(i, 0, word.size()) {
		if (word[i] == '*') {
			idx = i;
		}
	}
	int tmp = 0;
	int mul = 1;
	rep(i, 0, word.size()) {
		if (i == idx) {
			if (i & 1) {
				mul = 3;
			}
			continue;
		}
		if (i & 1) {
			tmp += (word[i] - '0') * 3;
		}
		else {
			tmp += (word[i] - '0');
		}
	}
	rep(i, 0, 10) {
		int target = tmp + i * mul;
		if (target % 10 == 0) {
			printf("%d", i);
			break;
		}
	}
	return 0;
}