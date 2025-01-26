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
typedef long long ll;

class SegmentTree {
public:
    vector<int> tree;
    int n;
    SegmentTree(const vector<int>& arr) : n(arr.size()) {
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) >> 1;
        build(arr, node * 2, start, mid);
        build(arr, node * 2 + 1, mid + 1, end);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(const vector<int>& arr, int node, int start, int end, int left, int right) {
        if (right < start || end < left) 
            return 1e9;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) >> 1;
        int tmp1 = query(arr, node * 2, start, mid, left, right);
        int tmp2 = query(arr, node * 2 + 1, mid + 1, end, left, right);
        return min(tmp1, tmp2);
    }

    void update(vector<int>&arr, int node, int start, int end, int index, int val) {
        if (index < start || index > end) return;
        if (start == end) {
            arr[index] = val;
            tree[node] = val;
            return;
        }
        int mid = (start + end) >> 1;
        update(arr, node * 2, start, mid, index, val);
        update(arr, node * 2 + 1, mid + 1, end, index, val);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
};
int main() {
    fastio;
    int n, q;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    SegmentTree st1(arr);
    int typ, b, e;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> typ >> b >> e;
        if (typ == 1) {
            st1.update(arr, 1, 0, n - 1, b - 1, e);
        }
        else {
            printf("%d\n", st1.query(arr, 1, 0, n - 1, b-1, e-1));
        }
    }
}