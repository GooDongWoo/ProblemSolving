#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;
string a, b;
int dict[26] = { 3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1 };
int main() {
	fastio;
	cin >> N >> M;
	cin >> a >> b;
	string tmp = "";
	rep(i, 0, max(a.size(), b.size())) {
		if (i < a.size())
			tmp += a[i];
		if (i < b.size())
			tmp += b[i];
	}
	vector<int> bef;
	rep(i, 0, tmp.size())
		bef.push_back(dict[tmp[i] - 'A']);
	vector<int> aft;
	while (bef.size() > 2) {
		rep(i, 1, bef.size()) {
			string stmp = to_string(bef[i - 1] + bef[i]);
			int slen = stmp.size();
			aft.push_back(stmp[slen - 1] - '0');
		}
		bef.swap(aft);
		aft.clear();
	}
	if (bef[0] == 0)
		printf("%d%%\n", bef[1]);
	else
		printf("%d%d%%\n", bef[0], bef[1]);
	return 0;
}