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
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> word;
	int N = word.size();
	rep(i, 0, N) {
		bef.push(word[i]);
	}
	cin >> M;
	rep(i, 0, M) {
		char cmd;
		cin >> cmd;
		if (cmd == 'L') {
			if (!bef.empty()) {
				aft.push(bef.top());
				bef.pop();
			}
		}
		else if (cmd == 'D') {
			if (!aft.empty()) {
				bef.push(aft.top());
				aft.pop();
			}
		}
		else if (cmd == 'B') {
			if (!bef.empty()) {
				bef.pop();
			}
		}
		else { // 'P'
			char val;
			cin >> val;
			bef.push(val);
		}
	}
	while (!bef.empty()) {
		aft.push(bef.top());
		bef.pop();
	}
	while (!aft.empty()) {
		cout << aft.top();
		aft.pop();
	}

	return 0;
}