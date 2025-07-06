#include <iostream>
#include <algorithm>
#define LL long long
#define rep(i,a,b) for(int i=a;i<b;++i)
using namespace std;

LL X, N, arr[1000000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		cin >> X >> N;
		if (cin.eof()) {
			break;
		}

		X *= 1e7;
		rep(i, 0, N) {
			cin >> arr[i];
		}
		if (N < 2) {
			printf("danger\n");
			continue;
		}
		sort(arr, arr + N);
		int start = 0, end = N - 1;
		bool found = false;
		while ((start < end) && (!found)) {
			int target = arr[start] + arr[end];
			if (target == X) {
				printf("yes %lld %lld\n", arr[start], arr[end]);
				found = true;
			}
			else if (target > X) {
				end--;
			}
			else {
				start++;
			}
		}
		if (!found) {
			printf("danger\n");
		}
	}
	return 0;
}