#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, Q;
    cin >> N >> M >> Q;
    
    vector<pair<ll, int>> products(N);
    vector<vector<int>> type_indices(M + 1);
    
    bool all_price_2 = true;
    
    for(int i = 0; i < N; i++) {
        cin >> products[i].first >> products[i].second;
        if(products[i].first != 2) all_price_2 = false;
        type_indices[products[i].second].push_back(i);
    }
    
    bool all_types_different = true;
    for(int i = 1; i <= M; i++) {
        if(type_indices[i].size() > 1) {
            all_types_different = false;
            break;
        }
    }
    
    vector<ll> prefix_sum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + products[i].first;
    }
    
    while(Q--) {
        int day, L, R;
        cin >> day >> L >> R;
        L--;
        
        ll total = prefix_sum[R] - prefix_sum[L];
        ll discount = 0;
        
        if(M == 1) {
            if(day == 1) {
                cout << total / 2 << '\n';
                continue;
            }
            cout << total << '\n';
            continue;
        }
        
        if(all_price_2) {
            int count = 0;
            for(int i = L; i < R; i++) {
                if(products[i].second == day) count++;
            }
            cout << 2 * (R - L) - count << '\n';
            continue;
        }
        
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