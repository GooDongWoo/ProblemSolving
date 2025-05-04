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

using namespace std;

LL p, q, a, n, ans;

LL gcd(LL a1, LL b1) {
	if (a1 == 0) return b1;
	if (b1 == 0) return a1;
	LL max1, min1;
	max1 = max(a1, b1);
	min1 = min(a1, b1);
	if (max1 % min1 == 0)
		return min1;
	return gcd(min1, max1 % min1);
}

set<vector<LL>> s1;
vector<LL> clist;
set<vector<LL>> v;

void bt(LL np, LL nq, LL idx, LL cur) {
	vector<LL> tmp(clist);
	sort(tmp.begin(), tmp.end());
	if (v.find(tmp) != v.end())
		return;
	v.insert(clist);

	if ((np == 0) || (idx == n - 1 && np != 1) || (clist.size() >= n))
		return;

	LL Limit = a / cur;
	if (np == 1) {
		if (cur * nq > a)
			return;
		tmp.push_back(nq);
		sort(tmp.begin(), tmp.end());
		s1.insert(tmp);
	}
	rep(i, 1, Limit + 1) {
		LL GCD = gcd(nq, i);
		LL LCM = nq * (i / GCD);
		LL upper = (np * LCM / nq) - (1 * LCM / i);
		if (upper > 0) {
			LL nGCD = gcd(upper, LCM);
			clist.push_back(i);
			bt(upper / nGCD, LCM / nGCD, idx + 1, cur * i);
			clist.pop_back();
		}
	}
}

int main() {
	fastio;
	cin >> p >> q >> a >> n;
	LL GCD = gcd(p, q);
	p = p / GCD;
	q = q / GCD;
	bt(p, q, 0, 1);
	ans = s1.size();
	printf("%lld\n", ans);
	return 0;
}