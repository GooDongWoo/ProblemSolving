#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;

int T, N;
string word;

bool run() {
	int idx = 0;
	while (idx < N) {
		if (idx < N && word[idx] == '0' &&
			idx + 1 < N && word[idx + 1] == '1') {
			idx += 2;
		}
		else if (
			idx < N && word[idx] == '1' &&
			idx + 1 < N && word[idx + 1] == '0' &&
			idx + 2 < N && word[idx + 2] == '0') {

			idx += 3;
			while (idx < N && word[idx] == '0') {
				idx++;
			}

			if (idx < N && word[idx] == '1') {
				idx++;
			}
			else {
				return false;
			}
			bool isCached = false;
			while (idx < N && word[idx] == '1') {
				idx++;
				isCached = true;
			}
			if (isCached && idx < N && word[idx] == '0' && idx + 1 < N && word[idx + 1] == '0') {
				idx--;
			}
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	cout.tie(NULL);

	cin >> T;
	rep(test_case, 0, T) {
		word.clear();
		cin >> word;
		N = word.size();
		cout << (run() ? "YES\n" : "NO\n");
	}
	return 0;
}