#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int T, N;
string num;

void F1(string& num, char target) {
	rep(i, 0, num.size()) {
		if (num[i] == '?') {
			num[i] = target;
		}
	}
}

int chck(string& num) {
	int fidx = num.find("1");
	if (fidx == -1) {
		return 1;
	}
	string n1 = "";
	rep(i, fidx, num.size()) {
		n1 += num[i];
	}
	if (n1.find('1', 1) == -1) {
		return N + n1.size() - 1;
	}
	else {
		return N + n1.size();
	}
}

int main() {
	fastio;
	cin >> T;
	rep(test_case, 1, T + 1) {
		cin >> N >> num;
		string min1(num), max1(num);
		F1(min1, '0');
		F1(max1, '1');
		int cnt1 = chck(min1);
		int cnt2 = chck(max1);
		printf("%d %d\n", cnt2, cnt1);
	}
	return 0;
}