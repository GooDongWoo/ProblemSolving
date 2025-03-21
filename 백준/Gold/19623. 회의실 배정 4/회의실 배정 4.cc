#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <set>
#include <cmath>
#include <cstring>
using namespace std;

struct Item {
    int s, e, num;
    bool operator<(const Item& o) const {
        return s < o.s;
    }
};

int main() {
    fastio;
    int N;
    cin >> N;
    
    vector<Item> items(N);
    unordered_map<int, int> compress; // Hash map for coordinate compression
    vector<int> coordinates;          // Stores unique coordinates
    coordinates.reserve(2 * N);       // Pre-allocate memory
    
    // Read input and collect unique coordinates
    rep(i, 0, N) {
        int a, b, c;
        cin >> a >> b >> c;
        items[i] = {a, b, c};
        
        // Add coordinates to the set if not already present
        if (compress.find(a) == compress.end()) {
            compress[a] = 0; // Temporary value
            coordinates.push_back(a);
        }
        if (compress.find(b) == compress.end()) {
            compress[b] = 0; // Temporary value
            coordinates.push_back(b);
        }
    }
    
    // Sort coordinates and perform coordinate compression
    sort(coordinates.begin(), coordinates.end());
    rep(i, 0, coordinates.size()) {
        compress[coordinates[i]] = i;
    }
    
    // Map items to compressed coordinates
    rep(i, 0, N) {
        items[i].s = compress[items[i].s];
        items[i].e = compress[items[i].e];
    }
    
    // Sort items by start time
    sort(items.begin(), items.end());
    
    // DP array with size equal to number of unique coordinates
    vector<int> dp(coordinates.size(), 0);
    
    // Process items in order
    int itemIdx = 0;
    rep(i, 0, coordinates.size()) {
        // Carry forward maximum value from previous coordinate
        if (i > 0) {
            dp[i] = max(dp[i], dp[i-1]);
        }
        
        // Process all items that start at current coordinate
        while (itemIdx < N && items[itemIdx].s == i) {
            dp[items[itemIdx].e] = max(dp[items[itemIdx].e], dp[i] + items[itemIdx].num);
            itemIdx++;
        }
    }
    
    cout << dp[coordinates.size() - 1] << endl;
    return 0;
}