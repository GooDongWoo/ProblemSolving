#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int m;
    cin >> m;
    
    vector<pair<int,int>> lines;
    while (true) {
        int left, right;
        cin >> left >> right;
        if (left == 0 && right == 0) break;
        
        if (left == right) continue;
        if (left < 0 && right <= 0) continue;
        
        lines.push_back({left, right});
    }
    
    sort(lines.begin(), lines.end());
    
    int curr_end = 0;  
    int count = 0;    
    int i = 0;         
    int max_reach = 0; 
    
    while (curr_end < m && i < lines.size()) {
        bool found = false;
        while (i < lines.size() && lines[i].first <= curr_end) {
            max_reach = max(max_reach, lines[i].second);
            found = true;
            i++;
        }
        
        if (!found || max_reach <= curr_end) {
            cout << "0\n";
            return 0;
        }
        
        curr_end = max_reach;
        count++;
    }
    
    if (curr_end >= m) cout << count << "\n";
    else cout << "0\n";
    
    return 0;
}