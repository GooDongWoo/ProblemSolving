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
#include <map>
#include <set>
#include <numeric>
#include <cmath>
#include <cstring>


using namespace std;

int n, cnters[1002];

int main() {
	fastio;
	cin >> n;
	string name;
	LL tmp;
	int val;
	rep(i, 0, n) {
		cin >> name >> tmp;
		if (name == "jinju")val = tmp;
		if (tmp > 1000) cnters[1001]++;
		else cnters[tmp]++;
	}
	int cnter = 0;
	rep(i, val + 1, 1002) cnter += cnters[i];
	printf("%d\n%d", val, cnter);
	return 0;
}