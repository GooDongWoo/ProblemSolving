#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class SegmentTree {
private:
    vector<pair<ll, int>> tree;
    int n;
public:
    SegmentTree(const vector<ll>& arr) : n(arr.size()) {
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void build(const vector<ll>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = { arr[start], start };
            return;
        }

        int mid = (start + end) >> 1;
        build(arr, node * 2 + 1, start, mid);
        build(arr, node * 2 + 2, mid + 1, end);
        tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);
    }

    pair<ll, int> query(int node, int start, int end, int left, int right) {
        if (right < start || end < left) return { LLONG_MAX, -1 };
        if (left <= start && end <= right) return tree[node];

        int mid = (start + end) >> 1;
        return min(query(node * 2 + 1, start, mid, left, right),
            query(node * 2 + 2, mid + 1, end, left, right));
    }
};

ll largest_rectangle(const vector<ll>& heights, SegmentTree& st, int start, int end, int n) {
    if (start > end) return 0;
    if (start == end) return heights[start];

    auto [min_height, min_idx] = st.query(0, 0, n - 1, start, end);
    ll area = min_height * (end - start + 1);

    return max({ area,
               largest_rectangle(heights, st, start, min_idx - 1, n),
               largest_rectangle(heights, st, min_idx + 1, end, n) });
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> heights(n);
    for (int i = 0; i < n; i++) cin >> heights[i];

    SegmentTree st(heights);
    cout << largest_rectangle(heights, st, 0, n - 1, n) << '\n';

}