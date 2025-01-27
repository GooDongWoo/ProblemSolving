#include <bits/stdc++.h>
#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

class SegmentTree {
public:
    vector<LL> tree;
    int n;
    SegmentTree(const vector<LL>& arr) : n(arr.size()) {
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(const vector<LL>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) >> 1;
        build(arr, node * 2, start, mid);
        build(arr, node * 2 + 1, mid + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    LL query(const vector<LL>& arr, int node, int start, int end, int left, int right) {
        if (right < start || end < left)
            return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) >> 1;
        LL tmp1 = query(arr, node * 2, start, mid, left, right);
        LL tmp2 = query(arr, node * 2 + 1, mid + 1, end, left, right);
        return tmp1 + tmp2;
    }

    void update(vector<LL>& arr, int node, int start, int end, int index, int val) {
        if (index < start || index > end) return;
        if (start == end) {
            arr[index] += val;
            tree[node] = arr[index];
            return;
        }
        int mid = (start + end) >> 1;
        update(arr, node * 2, start, mid, index, val);
        update(arr, node * 2 + 1, mid + 1, end, index, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
};
int main() {
    fastio;
    int n, q;
    cin >> n;
    vector<LL> arr(n, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    SegmentTree st1(arr);
    int b, e;
    char typ;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> typ >> b >> e;
        if (typ == 'U') {
            st1.update(arr, 1, 0, n - 1, b - 1, e);
        }
        else {
            LL ans = st1.query(arr, 1, 0, n - 1, b - 1, e - 1);
            printf("%lld\n", ans);
        }
    }
}