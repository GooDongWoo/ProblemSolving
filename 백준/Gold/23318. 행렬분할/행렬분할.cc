#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_set>
#include <functional>

using namespace std;

int N, M, A, B, arr[21][9], psum[21][9], Limit, ans;

vector<vector<int>> rs;
vector<vector<int>> cs;

vector<int> cds;
void bt1(int idx, int cur) {
	if (idx == A) {
		cds.push_back(N);
		rs.push_back(cds);
		cds.pop_back();
		return;
	}
	rep(i, cur, N + 1) {
		cds.push_back(i);
		bt1(idx + 1, i + 1);
		cds.pop_back();
	}
}

void bt2(int idx, int cur) {
	if (idx == B) {
		cds.push_back(M);
		cs.push_back(cds);
		cds.pop_back();
		return;
	}
	rep(i, cur, M + 1) {
		cds.push_back(i);
		bt2(idx + 1, i + 1);
		cds.pop_back();
	}
}

void cal(const vector<int>& rr, const vector<int>& cc) {
	int tmp = 0;
	rep(i, 1, A + 2) {
		rep(j, 1, B + 2) {
			int ar, ac, br, bc;
			ar = rr[i]; ac = cc[j];
			br = rr[i - 1]; bc = cc[j - 1];
			int curV = psum[ar][ac] - psum[ar][bc] - psum[br][ac] + psum[br][bc];
			tmp = max(tmp, curV);
			if (tmp >= ans)
				return;
		}
	}
	ans = min(ans, tmp);
}

int main() {
	fastio;
	cin >> N >> M >> A >> B;
	rep(i, 1, N + 1)
		rep(j, 1, M + 1)
		cin >> arr[i][j];
	rep(i, 1, N + 1)
		rep(j, 1, M + 1)
		psum[i][j] = psum[i][j - 1] + psum[i - 1][j] + arr[i][j] - psum[i - 1][j - 1];
	cds.push_back(0);
	bt1(0, 1);
	bt2(0, 1);
	ans = 1e9;
	for (const auto& rr : rs)
		for (const auto& cc : cs)
			cal(rr, cc);
	printf("%d\n", ans);
	return 0;
}