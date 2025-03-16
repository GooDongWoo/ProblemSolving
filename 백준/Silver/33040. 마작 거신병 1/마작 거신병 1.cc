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

LL H, W, C, D, arr[100000];

int main() {
	fastio;
	cin >> H >> W >> C >> D;
	LL N = H - 1;
	LL Limit = N * (N + 1) / 2;
	if (D < Limit || C < Limit) {
		printf("-1\n");
		return 0;
	}
	rep(i, 0, H)arr[i] = i;
	int Left1 = D - Limit;
	rep(i, 0, H) {
		if (i < H - (Left1 % H)) arr[i] += Left1 / H;
		else arr[i] += (Left1 / H) + 1;
	}
	rep(i, 0, H) {
		rep(j, 0, arr[i])printf("9 ");
		rep(j, 0, W - arr[i])printf("1 ");
		printf("\n");
	}
	return 0;
}