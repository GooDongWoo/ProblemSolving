#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int N;
vector<bool> chck1(7, 0);
vector<bool> chck2(7, 0);
bool Flag = 0;
int main() {
	fastio;
	cin >> N;
	int a;
	rep(i, 0, N) {
		cin >> a;
		a %= 7;
		chck2[a] = true;
		rep(i, 0, 7)
			if (chck1[i])
				chck2[(i + a) % 7] = true;
		chck1.swap(chck2);
		chck2.clear();
		if (chck1[4])
			Flag = 1;
	}
	if (Flag)
		printf("YES");
	else
		printf("NO");
	return 0;
}