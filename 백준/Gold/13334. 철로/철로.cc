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

typedef struct Items {
    int point, kind, idx;
    bool operator<(const Items& o) const {
        return(point < o.point);
    }
};
int N, L;
LL ans;
unordered_map<int,int> dict;
Items arr[200000];

int main() {
    fastio;
    cin >> N;
    rep(i, 0, N) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        arr[2 * i + 0] = { a,0,i };
        arr[2 * i + 1] = { b,1,i };
        dict[i] = 0;
    }
    cin >> L;
    sort(arr, arr + (2 * N));
    int left = 0, right = 0;
    LL mini = 0;
    while (left < (2 * N)) {
        LL target = arr[left].point + L;
        while (right < (2 * N) && arr[right].point <= target) {
            if (arr[right].kind == 0) {
                dict[arr[right].idx] |= (1 << 1);
            }
            else {
                dict[arr[right].idx] |= (1 << 0);
                if (dict[arr[right].idx] == 3) {
                    mini++;
                    ans = max(ans, mini);
                }
            }
            right++;
        }
        if (dict[arr[left].idx] == 3) mini--;
        dict[arr[left].idx] ^= (1 << 1);
        left++;
    }
    printf("%lld\n", ans);
    return 0;
}