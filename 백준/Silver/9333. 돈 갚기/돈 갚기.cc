#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int T;
LL B, R, M;

void Myreplace(string& tot, string bef, string aft) {
	int N = tot.size();
	int idx;
	while ((idx = tot.find(bef)) != -1) {
		tot.replace(tot.begin() + idx, tot.begin() + idx + bef.size(), aft);
	}
	return;
}
int main() {
	fastio;
	cin >> T;
	string a, b, c;
	rep(test_case, 1, T + 1) {
		cin >> a >> b >> c;
		Myreplace(a, ".", ""); R = stoi(a);
		Myreplace(b, ".", ""); B = stoi(b);
		Myreplace(c, ".", ""); M = stoi(c);

		int month = 0;
		while ((B > 0)) {
			month++;
			if (month > 1200)
				break;
			LL rate = round((B * R) / 10000.);
			B += rate;
			B -= M;
		}
		if (B > 0) {
			printf("impossible\n");
		}
		else {
			printf("%d\n", month);
		}
	}
}