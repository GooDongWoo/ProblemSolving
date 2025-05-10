#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, chck[8],cur[8];

void bt(int idx) {
	if (idx == N) {
		rep(i, 0, N)
			printf("%d ", cur[i]+1);
		printf("\n");
		return;
	}
	rep(i, 0, N) {
		if (chck[i])
			continue;
		chck[i] = 1;
		cur[idx] = i;
		bt(idx + 1);
		chck[i] = 0;
	}
}
int main() {
	fastio;
	cin >> N;
	bt(0);
	return 0;
}