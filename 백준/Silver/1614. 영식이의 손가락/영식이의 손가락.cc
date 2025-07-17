#define re(i,a,b) for(int i=a;i<b;++i)
#define LL long long

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

LL N, C;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> C;
	if (N == 1) {
		cout << 8 * C;
	}
	else if (N == 5) {
		cout << (8 * C) + 4;
	}
	else if (C & 1) {
		cout << (C - 1) * 4 + (9 - N);
	}
	else {
		cout << C * 4 + N - 1;
	}
	return 0;
}