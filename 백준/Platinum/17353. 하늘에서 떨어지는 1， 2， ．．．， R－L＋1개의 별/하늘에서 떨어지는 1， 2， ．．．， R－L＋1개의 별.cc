#include <iostream>
#include <vector>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using LL = long long;

const int MAXN = 100005;

int N, Q;
LL arr[MAXN];
pair<LL, LL> lazy[4 * MAXN];

void update(int idx, int l, int r, int ql, int qr, LL L_val) {
    if (l > qr || r < ql) {
        return;
    }
    if (ql <= l && r <= qr) {
        lazy[idx].first += 1;
        lazy[idx].second += L_val;
        return;
    }
    int mid = l + (r - l) / 2;
    update(2 * idx, l, mid, ql, qr, L_val);
    update(2 * idx + 1, mid + 1, r, ql, qr, L_val);
}

pair<LL, LL> query(int idx, int l, int r, int qidx) {
    if (l > qidx || r < qidx) {
        return { 0, 0 };
    }
    pair<LL, LL> current_lazy = lazy[idx];
    if (l == r) {
        return current_lazy;
    }
    int mid = l + (r - l) / 2;
    pair<LL, LL> child_lazy;
    if (qidx <= mid) {
        child_lazy = query(2 * idx, l, mid, qidx);
    }
    else {
        child_lazy = query(2 * idx + 1, mid + 1, r, qidx);
    }
    return { current_lazy.first + child_lazy.first, current_lazy.second + child_lazy.second };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    rep(i, 1, N + 1) {
        cin >> arr[i];
    }

    cin >> Q;
    rep(i, 0, Q) {
        int type;
        cin >> type;
        if (type == 1) {
            int L, R;
            cin >> L >> R;
            update(1, 1, N, L, R, L);
        }
        else {
            int X;
            cin >> X;
            pair<LL, LL> res = query(1, 1, N, X);
            LL count = res.first;
            LL sum_L = res.second;
            LL added_stars = (LL)(X + 1) * count - sum_L;
            cout << arr[X] + added_stars << "\n";
        }
    }

    return 0;
}