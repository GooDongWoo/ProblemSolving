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


int N, T;

int main() {
	fastio;
	cin >> N >> T;

	//int left = T % (4 * N - 2);
	int start = 1, incre = 1;

	rep(i, 1, T) {
		start += incre;
		if (start == 1 || start == 2 * N)
			incre *= -1;
	}
	printf("%d\n", start);
	return 0;
}