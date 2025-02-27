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
#include <queue>
#include <stack>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

int T, N,dp[1001];

int gcd(int a, int b) {
    if (a * b == 0) return 0;
    if (a < b)swap(a, b);
    if (a % b == 0)return b;
    return gcd(a % b, b);
}
int main() {
    fastio;
    dp[1] = 3;
    rep(i, 2, 1001) {
        dp[i] = dp[i - 1];
        rep(j, 1, i) {
            if (gcd(j, i) == 1) dp[i] += 2;
        }
    }
    cin >> T;
    rep(i, 0, T) {
        cin >> N;
        printf("%d\n", dp[N]);
    }
    return 0;
}