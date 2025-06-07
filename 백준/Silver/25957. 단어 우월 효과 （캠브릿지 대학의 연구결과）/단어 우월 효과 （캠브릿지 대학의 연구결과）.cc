#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

int N, M;
unordered_map<string, string> dict;

string makeKey(const string& a) {
    string tmp;
    tmp.reserve(28); // 최대 길이 예약
    
    tmp += a[0];
    if (a.size() != 1) {
        tmp += a.back(); // a[a.size()-1] 대신 back() 사용
    }
    
    int minimap[26] = {0}; // vector 대신 배열 사용
    for (int i = 1; i < (int)a.size() - 1; ++i) {
        minimap[a[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; ++i) {
        tmp += (char)('0' + minimap[i]);
    }
    
    return tmp;
}

int main() {
    fastio;
    
    cin >> N;
    dict.reserve(N); // 해시맵 크기 미리 예약
    
    rep(i, 0, N) {
        string a;
        cin >> a;
        string key = makeKey(a);
        dict[key] = move(a); // move semantics 사용
    }
    
    cin >> M;
    string ans;
    ans.reserve(M * 20); // 대략적인 크기 예약
    
    rep(i, 0, M) {
        string a;
        cin >> a;
        string key = makeKey(a);
        
        ans += dict[key];
        if (i < M - 1) ans += " "; // 마지막이 아닐 때만 공백 추가
    }
    
    cout << ans << "\n";
    return 0;
}