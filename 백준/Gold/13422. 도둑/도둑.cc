#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

int T, N, M, K, arr[200000], cnter;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	rep(test_case, 1, T + 1) {
		cin >> N >> M >> K;
		rep(i, 0, N) {
			int a;
			cin >> a;
			arr[i] = a;
			arr[N + i] = a;
		}
		int psum = 0;
		rep(i, 0, M) {
			psum += arr[i];
		}
		if (N == M) {
			if (psum >= K) {
				cout << "0\n";
			}
			else {
				cout << "1\n";
			}
			continue;
		}
		cnter = 0;
		rep(i, 0, N) {
			if (psum < K) {
				cnter++;
			}
			psum = psum - arr[i] + arr[i + M];
		}
		cout << cnter << '\n';
	}
	return 0;
}