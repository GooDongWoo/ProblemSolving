#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> tab_count(367, 0);
    vector<int> space_count(367, 0);
    
    int max_duration = 0;
    
    for (int i = 0; i < n; i++) {
        char c;
        int s, e;
        cin >> c >> s >> e;
        
        max_duration = max(max_duration, e - s + 1);
        
        for (int day = s; day <= e; day++) {
            if (c == 'T') {
                tab_count[day]++;
            } else {
                space_count[day]++;
            }
        }
    }
    
    int days_with_guests = 0;       // 투숙객이 1명 이상인 날의 수
    int max_guests = 0;             // 가장 많은 투숙객 수
    int no_fight_days = 0;          // 싸움이 없는 날의 수
    int max_guests_no_fight = 0;    // 싸움이 없는 날 중 가장 많은 투숙객 수
    
    for (int day = 1; day <= 366; day++) {
        int total_guests = tab_count[day] + space_count[day];
        
        if (total_guests > 0) {
            days_with_guests++;
            max_guests = max(max_guests, total_guests);
        }
        
        if (tab_count[day] > 0 && space_count[day] > 0 && 
            tab_count[day] == space_count[day]) {
            no_fight_days++;
            max_guests_no_fight = max(max_guests_no_fight, total_guests);
        }
    }
    
    cout << days_with_guests << "\n";           
    cout << max_guests << "\n";                 
    cout << no_fight_days << "\n";              
    cout << max_guests_no_fight << "\n";        
    cout << max_duration << "\n";               
    
    return 0;
}