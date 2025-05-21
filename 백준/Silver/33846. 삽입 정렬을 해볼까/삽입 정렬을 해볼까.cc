#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>

using namespace std;


int N, T, arr[1000000];

int main() {
	cin.tie(NULL);
	cin >> N >> T;
	rep(i, 0, N)
		cin >> arr[i];
	sort(arr, arr + T);
	rep(i, 0, N)
		printf("%d ", arr[i]);
	return 0;
}