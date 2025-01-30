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
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

int n, a[1000], cnter, idx, ans;
LL psum;

int main() {
    fastio;
    cin >> n;
    rep(i, 0, n) cin >> a[i];

    while (1) {
        int bef_idx = idx;
        psum = a[idx];
        cnter = 1;
        rep(i, idx+1, n) {
            if (psum < a[i] && idx == bef_idx) idx = i;
            else if (psum >= a[i]){
                cnter++;
                psum += a[i];
            }
        }
        ans = max(ans, cnter);
        if (idx == bef_idx) break;
    }

    printf("%d\n", ans);
    return 0;
}