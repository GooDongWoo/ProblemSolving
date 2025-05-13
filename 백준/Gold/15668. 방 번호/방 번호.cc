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

int N, LIMIT;
bool Flag, chck[10];
string cur;

bool F(string a) {
	bool minichck[10];
	memcpy(minichck, chck, 10 * sizeof(bool));
	rep(i, 0, a.size()) {
		if (minichck[a[i] - '0'])
			return false;
		minichck[a[i] - '0'] = 1;
	}
	return true;
}

void bt(int idx) {
	if (Flag)
		return;
	if (idx == 0) {
		rep(i, 1, 10) {
			chck[i] = 1;
			cur += to_string(i);
			bt(idx + 1);
			chck[i] = 0;
			cur.pop_back();
		}
	}
	else {
		LL left = N - stoll(cur);
		if (left <= 0)
			return;
		if (F(to_string(left))) {
			Flag = 1;
			printf("%s + %lld\n", cur.c_str(), left);
			return;
		}
		if (idx == LIMIT)
			return;
		rep(i, 0, 10) {
			if (chck[i])
				continue;
			chck[i] = 1;
			cur += to_string(i);
			bt(idx + 1);
			chck[i] = 0;
			cur.pop_back();
		}
	}
}

int main() {
	fastio;
	cin >> N;
	LIMIT = to_string(N).size();
	bt(0);
	if (!Flag)
		printf("-1\n");
	return 0;
}