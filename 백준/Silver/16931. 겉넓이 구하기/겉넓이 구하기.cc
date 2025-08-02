#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, M, arr[100][100], ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	rep(i, 0, N) {
		rep(j, 0, M) {
			cin >> arr[i][j];
		}
	}
	int tmp;
	//up&down
	ans += (2 * M * N);

	//left&right
	rep(i, 0, N) {
		int bef = 0;
		rep(j, 0, M) {
			ans += abs(arr[i][j] - bef);
			bef = arr[i][j];
		}
		ans += arr[i][M - 1];
	}
	//front&back
	rep(j, 0, M) {
		int bef = 0;
		rep(i, 0, N) {
			ans += abs(arr[i][j] - bef);
			bef = arr[i][j];
		}
		ans += arr[N-1][j];
	}
	cout << ans;
	return 0;
}