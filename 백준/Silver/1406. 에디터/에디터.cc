#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <string>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

int M;
string word;
stack<char> bef, aft;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> word;
	int N = word.size();
	rep(i, 0, N) {
		bef.push(word[i]);
	}
	cin >> M;
	rep(i, 0, M) {
		char cmd, val;
		cin >> cmd;
		if (cmd == 'L') {
			if (!bef.size()) {
				continue;
			}
			aft.push(bef.top());
			bef.pop();
		}
		else if (cmd == 'D') {
			if (!aft.size()) {
				continue;
			}
			bef.push(aft.top());
			aft.pop();
		}
		else if (cmd == 'B') {
			if (!bef.size()) {
				continue;
			}
			bef.pop();
		}
		else {
			cin >> val;
			bef.push(val);
		}
	}
	vector<char> arr;
	arr.resize(bef.size() + aft.size());

	while (aft.size() || bef.size()) {
		int idx = 0;
		while (aft.size()) {
			arr[bef.size() + idx++] = aft.top();
			aft.pop();
		}
		while (bef.size()) {
			arr[bef.size() - 1] = bef.top();
			bef.pop();
		}
	}
	for (const char a : arr) {
		cout << a;
	}
	return 0;
}