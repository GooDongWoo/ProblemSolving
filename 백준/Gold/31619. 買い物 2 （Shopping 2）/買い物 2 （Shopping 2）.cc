#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, Q;
    cin >> N >> M >> Q;
    
    vector<pair<ll, int>> products(N);
    for(int i = 0; i < N; i++) {
        cin >> products[i].first >> products[i].second;
    }
    
    vector<ll> prefix_sum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + products[i].first;
    }
    
    vector<vector<int>> type_indices(M + 1);
    for(int i = 0; i < N; i++) {
        type_indices[products[i].second].push_back(i);
    }
    
    while(Q--) {
        int day, L, R;
        cin >> day >> L >> R;
        L--;
        
        ll total = prefix_sum[R] - prefix_sum[L];
        
        ll discount = 0;
        if(!type_indices[day].empty()) {
            auto start = lower_bound(type_indices[day].begin(), type_indices[day].end(), L);
            auto end = upper_bound(type_indices[day].begin(), type_indices[day].end(), R-1);
            
            for(auto it = start; it != end; ++it) {
                int idx = *it;
                discount += products[idx].first / 2;
            }
        }
        
        cout << total - discount << '\n';
    }
    
    return 0;
}