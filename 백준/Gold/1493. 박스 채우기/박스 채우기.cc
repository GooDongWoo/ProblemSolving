#define rep(i,a,b) for(int i=a;i<b;++i)
#define LL long long
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

LL L, W, H, N, ans, arr[20];

void bt(LL cl, LL cw, LL ch) {
    LL min1 = min(cl, min(cw, ch));

    if (min1 == 1) {
        if (arr[0] >= cl * cw * ch) {
            arr[0] -= cl * cw * ch;
            ans += cl * cw * ch;
        }
        else {
            cout << -1;
            exit(0);
        }
        return;
    }

    LL idx = 0;
    while ((1 << (idx + 1)) <= min1) {
        idx++;
    }
    LL tmp = (1 << idx);

    if ((tmp == cl) && (cl == cw) && (cw == ch)) {
        if ((arr[idx] > 0)) {
            arr[idx]--;
            ans++;
            return;
        }
        else {
            tmp >>= 1;
            idx--;
        }
    }
    for (const LL x : {tmp, (cl - tmp)}) {
        for (const LL y : {tmp, (cw - tmp)}) {
            for (const LL z : {tmp, (ch - tmp)}) {
                if (x * y * z == 0) {
                    continue;
                }
                bt(x, y, z);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> L >> W >> H;
    cin >> N;
    rep(i, 0, N) {
        int a, b;
        cin >> a >> b;
        arr[a] += b;
    }
    bt(L, W, H);
    cout << ans;
    return 0;
}