#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<long long> customer(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> customer[i];
    }
    
    int block_size = max(1, (int)sqrt(N));
    int num_blocks = (N + block_size - 1) / block_size;
    vector<long long> block_min(num_blocks + 1);
    
    auto update_blocks = [&]() {
        for (int b = 0; b < num_blocks; b++) {
            block_min[b] = 1e18;
            int start = b * block_size + 1;
            int end = min(start + block_size - 1, N);
            for (int i = start; i <= end; i++) {
                block_min[b] = min(block_min[b], customer[i]);
            }
        }
    };
    
    update_blocks();
    
    for (int q = 0; q < Q; q++) {
        int S, T;
        long long P;
        cin >> S >> T >> P;
        
        long long current_plate = P;
        
        if (S <= T) {
            for (int i = S; i <= T; i++) {
                if (current_plate < customer[i]) {
                    swap(current_plate, customer[i]);
                }
            }
        } else {
            for (int i = S; i <= N; i++) {
                if (current_plate < customer[i]) {
                    swap(current_plate, customer[i]);
                }
            }
            for (int i = 1; i <= T; i++) {
                if (current_plate < customer[i]) {
                    swap(current_plate, customer[i]);
                }
            }
        }
        
        cout << current_plate << '\n';
    }
    
    return 0;
}