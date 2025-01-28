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

LL psum[100001];
LL solve(SegmentTree& st1, vector<LL>& arr, int n, int left, int right) {
    if (left > right) return 0;
    LL minidx = st1.query(arr,1, 0, n - 1, left, right).se;
    LL lw = arr[minidx];
    LL Lval = lw * (psum[right+1] - psum[left]);
    LL tmp1 = solve(st1, arr, n, left, minidx - 1);
    LL tmp2 = solve(st1, arr, n, minidx + 1, right);
    return max(Lval, max(tmp1, tmp2));
}
int main() {
    fastio;
    int n;
    cin >> n;
    vector<LL> arr(n, 0);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n; ++i) psum[i + 1] = psum[i] + arr[i];
    SegmentTree st1(arr);
    printf("%lld\n", solve(st1, arr, n, 0, n - 1));
    
}