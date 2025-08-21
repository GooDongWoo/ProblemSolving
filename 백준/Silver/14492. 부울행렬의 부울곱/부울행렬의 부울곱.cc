#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N,arr1[300][300],arr2[300][300],ans;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	rep(i, 0, N) {
		rep(j, 0, N) {
			cin >> arr1[i][j];
		}
	}
	rep(i, 0, N) {
		rep(j, 0, N) {
			cin >> arr2[i][j];
		}
	}
	rep(i, 0, N) {
		rep(j, 0, N) {
			rep(k, 0, N) {
				if (arr1[i][k] & arr2[k][j]) {
					ans++;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}