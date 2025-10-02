#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int i=(a);i<(b);++i)
using LL = long long;

using namespace std;

const int MAX = 360000;
int N, ff[MAX];
string word, target;
bool Flag = 0;

void makePI() {
	int cnt = 0;
	rep(cur, 1, MAX) {
		while (cnt > 0 && target[cur] != target[cnt]) {
			cnt = ff[cnt - 1];
		}
		if (target[cur] == target[cnt]) {
			ff[cur] = ++cnt;
		}
	}
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0);
	cin >> N;
	word.resize(2 * MAX);
	target.resize(MAX);
	rep(i, 0, N) {
		int a;
		cin >> a;
		a %= MAX;
		word[a] = '1';
		word[a + MAX] = '1';
	}
	rep(i, 0, N) {
		int a;
		cin >> a;
		target[a % MAX] = '1';
	}
	makePI();
	int cnt = 0;
	rep(cur, 0, 2 * MAX - 1) {
		while (cnt > 0 && word[cur] != target[cnt]) {
			cnt = ff[cnt - 1];
		}
		if (word[cur] == target[cnt]) {
			cnt++;
		}
		if (cnt == MAX) {
			Flag = 1;
			break;
		}
	}
	if (Flag) {
		cout << "possible";
	}
	else {
		cout << "impossible";
	}
	return 0;
}