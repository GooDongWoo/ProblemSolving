#include <iostream>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

string word;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> word;
	int N = word.size();
	int idx = 0;
	int lcnt = 0;
	long long ans = 0;
	char bef = ')';
	while (idx < N) {
		if (word[idx] == '(') {
			lcnt++;
		}
		else {
			lcnt--;
			if (bef == '(') {
				ans += lcnt;
			}
			else {
				ans += 1;
			}
		}
		bef = word[idx];
		idx++;
	}
	cout << ans;

	return 0;
}