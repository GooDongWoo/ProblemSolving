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
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

int N, a;

int main() {
	fastio;
	cin >> N;
	rep(i, 1, N+1) {
		char tmp;
		cin >> tmp;
		if (tmp == 'D') a++;
		if (abs(2 * a - i) >= 2) {
			printf("%d:%d\n",a,i-a);
			return 0;
		}
	}
	printf("%d:%d\n", a, N - a);
	return 0;
}