#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int N, M, arr[1000],tnum,ans,tmp,tt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	rep(i, 0, M) 
		cin >> arr[i];
	sort(arr, arr + M);
	tt = min(N, M);
	rep(i, 0, tt) {
		tmp = (tt - i) * arr[M - tt + i];
		if (tmp > ans) {
			ans = tmp;
			tnum = arr[M - tt + i];
		}
	}
	printf("%d %d", tnum, ans);
	return 0;
}