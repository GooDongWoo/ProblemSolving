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
#include <map>
#include <set>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX_N = 100000;
int N;
pair<int, int> arr[MAX_N];

int main() {
    fastio;
    cin >> N;
    rep(i, 0, N) cin >> arr[i].fi >> arr[i].se;
    sort(arr, arr + N);

    int oidx = 0, eidx = 0;
    rep(i, 0, N) {
        int cnt = 0;
        rep(j, 0, arr[i].se) {
            if (oidx < arr[i].fi) {
                oidx++;
                if(oidx % 7 == 5) oidx += 2;
            }
            else eidx++;
        }
        if (eidx > arr[i].fi) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n",eidx);
    return 0;
}