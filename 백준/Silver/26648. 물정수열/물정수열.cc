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

LL n, a[200000], b[200000], c[200000], bef, tmp1, tmp2;

int main() {
    fastio;

    cin >> n;
    rep(i, 0, n)cin >> a[i];
    rep(i, 0, n)cin >> b[i];
    rep(i, 0, n)cin >> c[i];
    
    bool flag = 1;
    bef = min(a[0], min(b[0], c[0]));
    rep(i, 1, n) {
        tmp1 = min(a[i], min(b[i], c[i]));
        tmp2 = max(a[i], max(b[i], c[i]));
        if (tmp2 <= bef) {
            flag = 0; break;
        }
        bef = max(bef + 1, tmp1);
    }
    if (flag) printf("YES\n");
    else printf("NO\n");

    return 0;
}