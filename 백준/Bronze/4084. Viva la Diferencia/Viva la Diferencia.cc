#include <iostream>
#include <vector>

using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)

int arr[4], narr[4];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		rep(i, 0, 4) cin >> arr[i];
		int tmp = 1;
		rep(i, 0, 4)tmp *= arr[i];
		if (tmp == 0) break;
		int cnter = 0;
		while (1) {
			if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3]) {
				printf("%d\n", cnter);
				break;
			}	
			rep(i, 0, 4)
				narr[i] = abs(arr[i] - arr[(i + 1) % 4]);
			rep(i, 0, 4)
				arr[i] = narr[i];
			cnter++;
		}
	}
	return 0;
}