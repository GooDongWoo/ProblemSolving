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
#include <deque>
#include <unordered_map>
#include <set>
#include <numeric>
#include <cmath>
#include <cstring>
using namespace std;

#define MOD 900528

int N, M, ans, dp1[1000001],dp2[1000001];
string a, b;
unordered_map<char, int> dict;

int main() {
    fastio;
    cin >> a >> b;
    N = a.size();
    M = b.size();
    rep(i, 0, N) dict[a[i]] = i;
    dp1[0] = 1; dp1[1] = N;
    rep(i, 2, M+1) dp1[i] = (dp1[i - 1] * N) % MOD;

    dp2[1] = 0; dp2[2] = N;
    rep(i, 3, M+1) dp2[i] = (dp2[i - 1] + dp1[i - 1]) % MOD;
    ans += dp2[M] + 1;
    rep(i, 0, M) {
        ans = (ans + (dict[b[M - 1 - i]]) * dp1[i]) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}