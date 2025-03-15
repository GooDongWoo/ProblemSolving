#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

int X1, X2, Y1, Y2, Z1, Z2, x1, x2, y_1, y2, z1, z2;

bool chck() {
	int f1 = 0, f2 = 0;
	if ((X1 < x1 && x1 < X2) || (X1 < x2 && x2 < X2))f1 = 1;
	if ((x1 < X1 && X1 < x2) || (x1 < X2 && X2 < x2))f1 = 1;
	if (x1==X1 && x2==X2)f1 = 1;

	if ((Y1 < y_1 && y_1 < Y2) || (Y1 < y2 && y2 < Y2))f2 = 1;
	if ((y_1 < Y1 && Y1 < y2) || (y_1 < Y2 && Y2 < y2))f2 = 1;
	if (y_1 == Y1 && y2 == Y2)f2 = 1;
	return (f1 && f2);
}
int main() {
	fastio;
	cin >> X1 >> X2 >> Y1 >> Y2 >> Z1 >> Z2 >> x1 >> x2 >> y_1 >> y2 >> z1 >> z2;
	if (chck() && Z2>=z1) {
		if ((z1 < Z1 && Z1 < z2) || (z1 < Z2 && Z2 < z2))printf("0");
		printf("%d", Z1-z2+1);
	}
	else {
		printf("-1");
	}

	return 0;
}