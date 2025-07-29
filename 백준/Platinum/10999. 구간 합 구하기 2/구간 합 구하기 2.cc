#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;
#define SIZE 1000001
LL arr[SIZE], segarr[4 * SIZE], lazy[4 * SIZE], N, M, K;

struct segtree {
    LL init(LL sidx, LL left, LL right) {
        if (left == right) {
            return segarr[sidx] = arr[left];
        }
        LL mid = (left + right) / 2;
        LL leftVal = init(2 * sidx, left, mid);
        LL rightVal = init(2 * sidx + 1, mid + 1, right);
        return segarr[sidx] = leftVal + rightVal;
    }

    void lazyProp(LL sidx, LL left, LL right) {
        if (lazy[sidx] != 0) {
            segarr[sidx] += (right - left + 1) * lazy[sidx];
            if (left != right) { 
                lazy[2 * sidx] += lazy[sidx];
                lazy[2 * sidx + 1] += lazy[sidx];
            }
            lazy[sidx] = 0;
        }
    }

    LL query(LL sidx, LL qleft, LL qright, LL left, LL right) {
        lazyProp(sidx, left, right);
        if (qright < left || right < qleft) {
            return 0;
        }
        if (qleft <= left && right <= qright) {
            return segarr[sidx];
        }
        LL mid = (left + right) / 2;
        LL leftVal = query(2 * sidx, qleft, qright, left, mid);
        LL rightVal = query(2 * sidx + 1, qleft, qright, mid + 1, right);
        return leftVal + rightVal;
    }

    void update(LL sidx, LL qleft, LL qright, LL left, LL right, LL val) {
        lazyProp(sidx, left, right);
        if (qright < left || right < qleft) {
            return;
        }
        if (qleft <= left && right <= qright) {
            lazy[sidx] += val;
            lazyProp(sidx, left, right);
            return;
        }
        LL mid = (left + right) / 2;
        update(2 * sidx, qleft, qright, left, mid, val);
        update(2 * sidx + 1, qleft, qright, mid + 1, right, val);

        lazyProp(2 * sidx, left, mid);
        lazyProp(2 * sidx + 1, mid + 1, right);
        segarr[sidx] = segarr[2 * sidx] + segarr[2 * sidx + 1];
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K;
    rep(i, 1, N + 1) {
        cin >> arr[i];
    }
    segtree seg;
    seg.init(1, 1, N);
    rep(i, 0, M + K) {
        LL a, b, c, d;
        cin >> a;
        if (a == 1) {
            cin >> b >> c >> d;
            seg.update(1, b, c, 1, N, d);
        }
        else {
            cin >> b >> c;
            cout << seg.query(1, b, c, 1, N) << '\n';
        }
    }
    return 0;
}