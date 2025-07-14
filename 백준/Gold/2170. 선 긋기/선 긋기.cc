#define rep(i,a,b) for(int i=a;i<b;++i)
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    // 정적 배열 사용으로 메모리 할당 최적화
    static pair<int, int> events[2000020];
    
    rep(i, 0, N) {
        int x, y;
        cin >> x >> y;
        events[2*i] = {x, 0};     // 선분 시작점
        events[2*i+1] = {y, 1};   // 선분 끝점
    }
    
    sort(events, events + 2*N);
    
    long long ans = 0;  // 좌표 범위가 클 수 있으므로 long long 사용
    int active_count = 0;
    int union_start = 0;
    
    rep(i, 0, 2*N) {
        if (events[i].second == 0) {  // 선분 시작
            if (active_count == 0) {
                union_start = events[i].first;
            }
            active_count++;
        } else {  // 선분 끝
            active_count--;
            if (active_count == 0) {
                ans += events[i].first - union_start;
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}