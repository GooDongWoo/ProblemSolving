#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int N;
unordered_map<string, bool> dict;

int main() {
	fastio;
	cin >> N;
	rep(i, 0, N) {
		string name;
		cin >> name;
		dict[name] = 1;
	}
	rep(i, 0, N - 1) {
		string name;
		cin >> name;
		dict[name] = 0;
	}
	for (auto& x : dict) {
		if (x.second == 1) {
			printf("%s\n", x.first.c_str());
			break;
		}
	}
	return 0;
}