#include <iostream>
#include <algorithm>
#include <string>

#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int T;
string word;

int postOrder(int start, int end) {
	if (end - start == 1) {
		return 2;
	}
	int ls = start + 1, le = 0;
	int rs = 0, re = end - 1;
	int lcnter = 0, rcnter = 0;
	int idx = ls;
	// start+1 ~ end-1까지 각각 left와 right 범위를 구한다.
	while (idx <= re) {
		if (word[idx] == '[') {
			lcnter++;
		}
		else {
			rcnter++;
		}
		if (lcnter == rcnter) {
			le = idx;
			rs = idx + 1;
			break;
		}
		idx++;
	}
	// 그리고 각각 필요한 원숭이 수를 재귀로 보내면서 구해온다.
	int left = postOrder(ls, le);
	if (le != re) {
		int right = postOrder(rs, re);
		// left랑 right를 비교하고 같으면 합 리턴하고 다르면 계산 ㄴㄴ 큰수로 통일한다.
		return max(left, right) * 2;
	}
	else {
		return 2 * left;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	cin.ignore();
	rep(i, 0, T) {
		getline(cin, word);
		if (word.size() == 0) {
			cout << "1\n";
			continue;
		}
		cout << postOrder(0, word.size() - 1) << '\n';
	}
	return 0;
}