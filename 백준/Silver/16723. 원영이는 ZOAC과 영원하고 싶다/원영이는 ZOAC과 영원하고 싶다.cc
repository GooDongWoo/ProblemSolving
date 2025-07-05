#include <iostream>
#include <algorithm>
#include <cmath>
#define LL long long
using namespace std;

int N;

int main() {
	cin >> N;
	LL res = N;
	LL p2 = 2;
	while (p2 <= N) {
		res += (p2 / 2) * (N / p2);
		p2 *= 2;
	}
	printf("%lld", res*2);
}