#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>

using namespace std;

int N, M, arr[100000], dat[100000];
LL cw, ccw;
int main() {
	fastio;
	cin >> N >> M; M--;
	rep(i, 0, N) {
		cin >> arr[i];
		arr[i]--;
		dat[arr[i]] = i;
	}
	int cidx = 0;
	int bidx = 0;
	while (cidx != M) {
		cw += (N + (dat[cidx] - bidx)) % N;
		bidx = dat[cidx];
		cidx++;
	}
	cidx = 0;
	bidx = 0;
	while (cidx != M) {
		ccw += (N + (dat[(cidx - 1 + N) % N] - bidx)) % N;
		bidx = dat[(cidx - 1 + N) % N];
		cidx = (cidx - 1 + N) % N;
	}
	if (ccw < cw)
		printf("CCW\n");
	else if (ccw == cw)
		printf("EW\n");
	else
		printf("CW\n");
	return 0;
}