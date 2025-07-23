#define rep(i, a, b) for (int i = a; i < b; ++i)
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

struct Item {
    long double cnt, x, y;
    int idx;
    bool operator>(const Item& b) const {
        return cnt > b.cnt;
    }
};

int N;
long double sx, sy, ex, ey, ans, dp[100];
pair<long double, long double> arr[100];
priority_queue<Item, vector<Item>, greater<>> pq;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> sx >> sy >> ex >> ey;
    cin >> N;
    rep(i, 0, N) {
        long double tx, ty, tmp;
        cin >> tx >> ty;
        arr[i] = { tx, ty };
        dp[i] = 1e9;
        tmp = sqrt((sx - tx) * (sx - tx) + (sy - ty) * (sy - ty)) / 5;
        pq.push({ tmp, tx, ty, i });
    }

    ans = sqrt((sx - ex) * (sx - ex) + (sy - ey) * (sy - ey)) / 5;

    while (pq.size()) {
        auto curp = pq.top();
        pq.pop();
        long double cv = curp.cnt, cx = curp.x, cy = curp.y;
        int cidx = curp.idx;

        if (dp[cidx] <= cv) {
            continue;
        }
        dp[cidx] = cv;

        rep(i, 0, N) {
            if (i == cidx) continue;

            long double nx = arr[i].first, ny = arr[i].second;
            long double rawLen = sqrt((cx - nx) * (cx - nx) + (cy - ny) * (cy - ny));
            long double dt = min(rawLen / 5, 2.0 + abs(rawLen - 50.0) / 5);

            if (dp[i] > dt + cv) {
                pq.push({ dt + cv, nx, ny, i });
            }
        }

        long double rawLen = sqrt((cx - ex) * (cx - ex) + (cy - ey) * (cy - ey));
        ans = min(ans, cv + min(rawLen / 5, 2.0 + abs(rawLen - 50.0) / 5));
    }

    cout << fixed << setprecision(6) << ans;
    return 0;
}