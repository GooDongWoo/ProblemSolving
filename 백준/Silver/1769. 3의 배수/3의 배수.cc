#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int cnter;
string word;

void F(string& num) {
	int tmp = 0;
	rep(i, 0, num.size()) {
		tmp += num[i] - '0';
	}
	num = to_string(tmp);
	return;
}


int main() {
	fastio;
	cin >> word;
	while (word.size() != 1) {
		F(word);
		cnter++;
	}
	int last = stoi(word);
	printf("%d\n", cnter);
	if (last % 3 == 0 && last / 3 > 0) {
		printf("YES");
	}
	else {
		printf("NO");
	}

}