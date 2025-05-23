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
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cstring>

using namespace std;

int N, M, ans;
char arr[8];
string cur = "";
bool chck(string sn) {
	rep(i, 0, M)
		if (cur.find(arr[i]) == cur.npos)
			return false;
	return true;
}
void bt(int idx) {
	if (idx == N) {
		if (chck(cur))
			ans++;
	}
	else {
		rep(i, 0, 10) {
			cur += '0' + i;
			bt(idx + 1);
			cur.pop_back();
		}
	}
}
int main() {
	cin.tie(NULL);
	cin >> N >> M;
	rep(i, 0, M)
		cin >> arr[i];
	string LIMITs = "";
	bt(0);
	printf("%d\n", ans);
	return 0;
}