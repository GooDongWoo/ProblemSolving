#define rep(i,a,b) for(int i=a;i<b;++i)

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N, M,arr[2000000];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	rep(i, 0, N + M)
		cin >> arr[i];
	sort(arr, arr + N + M);
	rep(i, 0, N + M)
		printf("%d ", arr[i]);
	return 0;
}