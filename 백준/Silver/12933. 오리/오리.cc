#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

int N, ccnt, cidx, ans, minicnter;
string word, duck = "quack";
bool v[2500];

int main() {
	fastio;
	cin >> word;
	N = word.size();
	while (ccnt < N) {
		minicnter = 0;
		rep(i, 0, N) {
			if (v[i])continue;
			if (word[i] == duck[cidx]) {
				v[i] = 1; ccnt++;
				cidx = (cidx + 1) % 5;
				if (cidx == 0)minicnter = 1;
			}
		}
		if (cidx != 0 ||(cidx==0 && minicnter==0)) {
			printf("-1\n");
			return 0;
		}
		if (minicnter) ans++;
	}
	printf("%d\n", ans);
	return 0;
}