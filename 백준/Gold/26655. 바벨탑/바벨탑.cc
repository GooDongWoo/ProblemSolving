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
#include <map>

using namespace std;

class SegmentTree {
public:
    vector<pair<LL, LL>> tree;
    int n;
    SegmentTree(const vector<LL>& arr) : n(arr.size()) {
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(const vector<LL>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = { arr[start], start};
            return;
        }
        int mid = (start + end) >> 1;
        build(arr, node * 2, start, mid);
        build(arr, node * 2 + 1, mid + 1, end);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    pair<LL, LL> query(const vector<LL>& arr, int node, int start, int end, int left, int right) {
        if (right < start || end < left)
            return { 1e9, 1e9 };
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) >> 1;
        pair<LL, LL> tmp1 = query(arr, node * 2, start, mid, left, right);
        pair<LL, LL> tmp2 = query(arr, node * 2 + 1, mid + 1, end, left, right);
        return min(tmp1, tmp2);
    }

    void update(vector<LL>& arr, int node, int start, int end, int index, int val) {
        if (index < start || index > end) return;
        if (start == end) {
            arr[index] = val;
            tree[node] = { arr[index] , index };
            return;
        }
        int mid = (start + end) >> 1;
        update(arr, node * 2, start, mid, index, val);
        update(arr, node * 2 + 1, mid + 1, end, index, val);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
};

LL cnter, curw;
void solve(SegmentTree& st1, vector<LL>& arr, int n, int left, int right, LL cw) {
    if (left > right) return ;
    LL minidx = st1.query(arr,1, 0, n - 1, left, right).se;
    LL lw = arr[minidx] - cw;
    LL Lcnter = 0;
    
    Lcnter += lw / 20; lw %= 20;
    Lcnter += lw / 15; lw %= 15;
    Lcnter += lw / 10; lw %= 10;
    Lcnter += lw / 5; lw %= 5;
    cnter += (4 * Lcnter);
    cw = arr[minidx];

    solve(st1, arr, n, left, minidx-1, cw);
    solve(st1, arr, n, minidx + 1, right, cw);
    return ;
}
int main() {
    fastio;
    int n, q;
    cin >> n;
    vector<LL> arr(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i] = (arr[i] - 20) / 2;
    }
    SegmentTree st1(arr);
    LL totw = 0;
    rep(i, 1, n) totw += abs(arr[i] - arr[i - 1]);
    totw += arr[0] + arr[n - 1]; totw *= 2;
    solve(st1, arr, n, 0, n - 1, curw);
    printf("%lld %lld\n", totw, cnter);
    /*int b, e;
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
    }*/
}