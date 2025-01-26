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

class SegmentTree1 {
public:
    vector<int> tree;
    int n;
    SegmentTree1(const vector<int>& arr) : n(arr.size()) {
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

    int query(int node, int start, int end, int left, int right) {
        if (right < start || end < left) return 1e9;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) >> 1;
        return min(query(node * 2, start, mid, left, right), 
            query(node * 2 + 1, mid + 1, end, left, right));
    }

    void update(vector<int>&arr, int node, int start, int end, int index, int val) {
        if (index < start || index > end) return;
        if (start == end) {
            arr[index] = val;
            tree[node] = (arr[start] & 1) ? 1 : 0;
            return;
        }
        int mid = (start + end) >> 1;
        update(arr, node * 2, start, mid, index, val);
        update(arr, node * 2 + 1, mid + 1, end, index, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
};
class SegmentTree2 {
public:
    vector<int> tree;
    int n;
    SegmentTree2(const vector<int>& arr) : n(arr.size()) {
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
        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int start, int end, int left, int right) {
        if (right < start || end < left) return 0;
        if (left <= start && end <= right) return tree[node];
        int mid = (start + end) >> 1;
        return max(query(node * 2, start, mid, left, right),
            query(node * 2 + 1, mid + 1, end, left, right));
    }

    void update(vector<int>& arr, int node, int start, int end, int index, int val) {
        if (index < start || index > end) return;
        if (start == end) {
            arr[index] = val;
            tree[node] = (arr[start] & 1) ? 1 : 0;
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
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    SegmentTree1 st1(arr);
    int b, e;
    for (int i = 0; i < q; i++) {
        cin >> b >> e;
        printf("%d\n", st1.query(1, 0, n - 1, b - 1, e - 1));
        /*if (typ == 1) {
            st1.update(arr, 1, 0, n - 1, b - 1, e);
        }
        else if (typ == 2) {
            printf("%d\n", e - b + 1 - st1.query(1, 0, n - 1, b - 1, e - 1));
        }
        else {
            printf("%d\n", st1.query(1, 0, n - 1, b - 1, e - 1));
        }*/
    }
}