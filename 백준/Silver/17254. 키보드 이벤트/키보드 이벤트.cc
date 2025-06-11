#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int N, M;
vector<vector<int>> big1;

int main() {
	fastio;
	cin >> N >> M;
	rep(i, 0, M) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		vector<int> tmp = { b,a,c };
		big1.push_back(tmp);
	}
	sort(big1.begin(), big1.end());
	for (const auto& x : big1) {
		printf("%c", x[2]);
	}
	return 0;
}