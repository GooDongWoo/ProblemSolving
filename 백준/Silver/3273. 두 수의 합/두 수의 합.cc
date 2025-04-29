#include<iostream>
#include<queue>
#include<algorithm>
#include<climits>
#include<vector>
#include<unordered_map>
#include<cstring>

using namespace std;

#define fastio ios_base ::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define rep(i,a,b) for(int i=a;i<b;i++)


int N, X, arr[1000001], ans;


int main() {
	cin >> N;
	int a;
	rep(i, 0, N) {
		cin >> a;
		arr[a]++;
	}
	cin >> X;
	int upper = (X & 1) ? X / 2 + 1 : X / 2;
	rep(i, 1, upper) {
		if (i >= 1000001)
			break;
		if (arr[i] > 0 && X - i < 1000001 && arr[X - i] > 0)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}