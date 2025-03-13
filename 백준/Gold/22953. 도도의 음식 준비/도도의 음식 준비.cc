#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

int N, K, C;
LL ans;
set<vector<int>> s1;
vector<int> arr;  

void BT(int idx) {
    if (idx == C) {
        s1.insert(arr);
        return;  
    }
    else {
        int Flag = 1;
        rep(i, 0, N) {
            if (arr[i] > 1) {
                arr[i]--;
                Flag = 0;
                BT(idx + 1);
                arr[i]++;
            }
        }
        if (Flag) BT(C);
    }
}


bool F(LL time, const vector<int>& items) {
    LL cnt = 0;
    rep(i, 0, N) {
        cnt += time / items[i];
    }
    return cnt >= K;
}

int main() {
    fastio;
    cin >> N >> K >> C;
    arr.resize(N);  
    rep(i, 0, N) cin >> arr[i];
    BT(0);
    ans = 1e13;
    for (const auto& case1 : s1) {
        LL start = 1;
        LL end = 1e13;

        while (start <= end) {
            LL mid = start + (end - start) / 2;
            if (F(mid, case1)) {
                ans = min(ans, mid);
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}