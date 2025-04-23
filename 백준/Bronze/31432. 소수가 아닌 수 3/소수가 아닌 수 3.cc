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

int N;

int main() {
	fastio;
	int tt;
	cin >> N;
	rep(i, 0, N)
		cin >> tt;
	printf("YES\n");
	if (tt)
		if (tt == 1)
			printf("%d", tt);
		else
			printf("%d%d", tt, tt);
	else
		printf("%d", tt);
}