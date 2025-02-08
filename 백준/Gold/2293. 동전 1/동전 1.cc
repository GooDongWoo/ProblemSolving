#include <iostream>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<b;++i)

using namespace std;

int n, k, arr[100], dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    rep(i, 0, n) cin >> arr[i];
    rep(i, 0, n) {
        int t = arr[i];
        if (t > 10000) continue;
        dp[t] += 1;
        rep(j, t + 1, k+1) dp[j] += dp[j - t];
    }
    printf("%d\n", dp[k]);
    return 0;
}