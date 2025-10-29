#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define rep(i,a,b) for(int i=a;i<b;++i)
using namespace std;

struct Item {
    int val, idx;
    bool operator<(const Item& b) const {
        if (val != b.val) return val < b.val;
        return idx > b.idx;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, K;
    string word;
    cin >> N >> K >> word;
    
    priority_queue<Item> pq;
    string result = "";
    int prev = -1;
    int remain = N - K;
    
    for (int i = 0; i <= K; i++) {
        pq.push({word[i] - '0', i});
    }
    
    for (int i = 0; i < remain; i++) {
        int end = K + i;  
        
        while (!pq.empty() && pq.top().idx <= prev) {
            pq.pop();
        }
        
        if (i > 0 && end < N) {
            pq.push({word[end] - '0', end});
        }
        
        auto selected = pq.top();
        result += (char)('0' + selected.val);
        prev = selected.idx;
    }
    
    cout << result << '\n';
    return 0;
}