#include <iostream>
#include <vector>
#include <numeric>
#include <tuple>

using ll = long long;

std::vector<ll> seg_tree;
int N; 

void update(int node, int start, int end, int idx, int value) {
    if (start == end) {
        seg_tree[node] += value;
        return;
    }
    int mid = (start + end) / 2;
    if (start <= idx && idx <= mid) {
        update(2 * node, start, mid, idx, value);
    } else {
        update(2 * node + 1, mid + 1, end, idx, value);
    }
    seg_tree[node] = seg_tree[2 * node] + seg_tree[2 * node + 1];
}

ll query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return 0; 
    }
    if (l <= start && end <= r) {
        return seg_tree[node]; 
    }
    int mid = (start + end) / 2;
    ll p1 = query(2 * node, start, mid, l, r);
    ll p2 = query(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M, Q;
    std::cin >> N >> M >> Q;

    std::vector<std::vector<std::pair<int, int>>> products_by_type(M + 1);
    std::vector<ll> total_prefix_sum(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        int p, a;
        std::cin >> p >> a;
        products_by_type[a].push_back({i, p});
        total_prefix_sum[i] = total_prefix_sum[i - 1] + p;
    }

    std::vector<std::vector<std::tuple<int, int, int>>> queries_by_day(M + 1);
    for (int i = 0; i < Q; ++i) {
        int t, l, r;
        std::cin >> t >> l >> r;
        queries_by_day[t].push_back({l, r, i});
    }

    seg_tree.resize(4 * N + 4, 0);
    
    std::vector<ll> answers(Q);

    for (int day = 1; day <= M; ++day) {
        for (const auto& product : products_by_type[day]) {
            int product_idx = product.first;
            int product_price = product.second;
            update(1, 1, N, product_idx, product_price / 2);
        }

        for (const auto& q : queries_by_day[day]) {
            int l, r, original_idx;
            std::tie(l, r, original_idx) = q;

            ll full_price_sum = total_prefix_sum[r] - total_prefix_sum[l - 1];

            ll discount_sum = query(1, 1, N, l, r);
            
            answers[original_idx] = full_price_sum - discount_sum;
        }
        
        for (const auto& product : products_by_type[day]) {
            int product_idx = product.first;
            int product_price = product.second;
            update(1, 1, N, product_idx, -product_price / 2);
        }
    }

    for (int i = 0; i < Q; ++i) {
        std::cout << answers[i] << "\n";
    }

    return 0;
}