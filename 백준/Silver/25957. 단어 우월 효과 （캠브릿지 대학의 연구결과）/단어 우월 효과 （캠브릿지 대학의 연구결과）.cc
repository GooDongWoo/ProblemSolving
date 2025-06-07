#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int N, M;
unordered_map<string, string> dict;

int main() {
	fastio;
	cin >> N;
	rep(i, 0, N) {
		string a;
		string tmp = "";
		cin >> a;
		tmp += a[0];
		if (a.size() != 1) {
			tmp += a[a.size() - 1];
		}
		vector<int> minimap(26);
		rep(i, 1, a.size() - 1) {
			minimap[a[i] - 'a']++;
		}
		rep(i, 0, 26) {
			tmp += '0' + minimap[i];
		}
		dict[tmp] = a;
	}
	cin >> M;
	rep(i, 0, M) {
		string a;
		string tmp = "";
		cin >> a;
		tmp += a[0];
		if (a.size() != 1) {
			tmp += a[a.size() - 1];
		}
		vector<int> minimap(26);
		rep(i, 1, a.size() - 1) {
			minimap[a[i] - 'a']++;
		}
		rep(i, 0, 26) {
			tmp += '0' + minimap[i];
		}
		printf("%s ", dict[tmp].c_str());
	}
	return 0;
}