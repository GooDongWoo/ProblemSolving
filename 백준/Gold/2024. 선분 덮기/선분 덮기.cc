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


int m, n, dp[50001], ans;

int main() {
    fastio;
    cin >> m;
    int left, right;
    while (1) {
        cin >> left >> right;
        if (left == 0 && right == 0) break;
        if (left == right) continue;
        if (right > 0) {
            dp[max(left, 0)] = max(dp[max(left, 0)], min(right, 50000));
        }
    }
    if (dp[0] == 0) {
        printf("0\n");
        return 0;
    }
    int curr = dp[0], curl = 1, nr = 0;
    ans = 1;
    while (curr < m) {
        rep(i, curl, curr+1) {
            if (dp[i] == 0) continue;
            if (dp[i] > nr) {
                nr = dp[i];
            }
        }
        if (nr > curr) {
            ans++;
            curl = curr+1;
            curr = nr;
        }
        else {
            printf("0\n");
            return 0;
        }
    }
    printf("%d\n", ans);    
    return 0;
}