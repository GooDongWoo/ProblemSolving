#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <string>
#define rep(i,a,b) for(int i=a;i<b;++i)
#define LL long long

using namespace std;

const int LIMIT = 500;
int N, K, arr[8], memo[256], weight, state;
LL cnter;

void bt(int idx) {
	if (idx == N) cnter++;
	else if (memo[state]) cnter += memo[state];
	else {
		rep(i, 0, N) {
			if (state & (1 << i)) continue;
			if (weight + arr[i] - K < LIMIT) continue;
			state ^= (1 << i);
			weight += arr[i] - K;
			bt(idx + 1);
			weight -= arr[i] - K;
			state ^= (1 << i);
			memo[state] += memo[state ^ (1 << i)];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	memo[(1 << N) - 1] = 1; weight = LIMIT;
	rep(i, 0, N)cin >> arr[i];
	bt(0);
	printf("%lld\n", cnter);
	return 0;
}