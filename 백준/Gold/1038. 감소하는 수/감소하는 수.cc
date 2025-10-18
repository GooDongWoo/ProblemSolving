#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define rep(i,a,b) for(int i=a;i<b;++i)
using LL = long long;

using namespace std;

LL N, cur;
vector<LL> Candidates;

void bt(LL idx, LL bef) {
	rep(i, bef + 1, 10) {
		LL pVal = pow(10, idx) * i;
		cur += pVal;
		Candidates.push_back(cur);
		bt(idx + 1, i);
		cur -= pVal;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	cin >> N;
	bt(0, -1);
	sort(Candidates.begin(), Candidates.end());
	cout << ((Candidates.size() > N) ? Candidates[N] : -1);
}