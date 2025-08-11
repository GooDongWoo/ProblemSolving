#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int X, N;
vector<string> arr;
string origin;

void Func(string& inp) {
	string tmp = "";
	int idx = 0;
	while (tmp.size() < N) {
		tmp += inp[idx];
		tmp += inp[N - 1 - idx];
		idx++;
	}
	if (tmp.size() != N) {
		tmp.pop_back();
	}
	inp = tmp;
	return;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> X >> origin;
	N = origin.size();

	string word = origin;
	arr.push_back(word);
	Func(word);
	while (word != origin) {
		arr.push_back(word);
		Func(word);
	}
	X %= arr.size();
	cout << arr[(arr.size() - X) % arr.size()];
	return 0;
}