#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <unordered_map>
#include <cmath>
#include <string>
#include <cstring>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;
using LL = long long;
using UI = unsigned int;

int N, M, arr[1000], tl[1000], tr[1000], ret[1000], tmp;

int main() {
	cin.tie(NULL)->sync_with_stdio(false);

	cin >> N >> M;

	cin >> arr[0];
	ret[0] = arr[0];
	rep(i, 1, M) {
		cin >> arr[i];
		ret[i] = ret[i - 1] + arr[i];
	}

	rep(i, 1, N) {
		rep(j, 0, M) {
			cin >> arr[j];
		}
		rep(j, 0, M) {
			// left -> right
			if (j == 0) {
				tl[j] = ret[j] + arr[j];
			}
			else {
				tl[j] = max(ret[j], tl[j - 1]) + arr[j];
			}

			// left <- right
			if (j == 0) {
				tr[M - 1 - j] = ret[M - 1 - j] + arr[M - 1 - j];;
			}
			else {
				tr[M - 1 - j] = max(ret[M - 1 - j], tr[M - j]) + arr[M - 1 - j];
			}
		}
		rep(j, 0, M) {
			ret[j] = max(tl[j], tr[j]);
		}
	}
	cout << ret[M - 1];
	return 0;
}