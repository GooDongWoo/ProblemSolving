#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>

using namespace std;

int N, Q, up1;
string cur, cst = "SciComLove";

int main() {
	fastio;
	cin >> N >> Q;
	cur.resize(N);
	rep(i, 0, N) {
		if (isupper(cst[i % 10]))
			up1++;
		cur[i] = cst[i % 10];
	}
	rep(i, 0, Q) {
		int a;
		cin >> a;a--;
		if (isupper(cur[a])) {
			cur[a] = tolower(cur[a]);
			up1--;
		}
		else {
			cur[a] = toupper(cur[a]);
			up1++;
		}
		printf("%d\n", up1);
	}
	return 0;
}