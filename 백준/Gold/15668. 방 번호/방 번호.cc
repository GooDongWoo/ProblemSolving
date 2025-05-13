#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int N, LIMIT;
bool Flag;
bool used[10]; // 사용된 숫자 추적
string result_a, result_b; // 결과 저장용

// 숫자의 각 자릿수가 중복되지 않는지 검사
bool hasUniqueDigits(LL num) {
    bool temp[10] = {0};
    
    while (num > 0) {
        int digit = num % 10;
        if (used[digit] || temp[digit]) return false;
        temp[digit] = true;
        num /= 10;
    }
    return true;
}

// 백트래킹 - 숫자로 직접 계산
void bt(int idx, LL current) {
    if (Flag) return;
    
    if (idx >= 1) {
        LL left = N - current;
        
        // 가지치기: 음수면 더 탐색할 필요 없음
        if (left <= 0) return;
        
        // left가 아직 사용하지 않은 숫자들로만 구성되어 있는지 확인
        if (hasUniqueDigits(left)) {
            Flag = true;
            result_a = to_string(current);
            result_b = to_string(left);
            return;
        }
        
        // 가지치기: 최대 자릿수 초과
        if (idx == LIMIT) return;
    }
    
    // 첫 자리는 0이 될 수 없음
    int start = (idx == 0) ? 1 : 0;
    
    for (int i = start; i < 10; i++) {
        if (used[i]) continue;
        
        used[i] = true;
        bt(idx + 1, current * 10 + i);
        used[i] = false;
        
        // 가지치기: 첫 번째 숫자의 모든 경우를 다 시도해봤지만 답이 없다면 종료
        if (idx == 0 && i == 9 && !Flag) return;
    }
}

int main() {
    fastio;
    cin >> N;
    LIMIT = to_string(N).size();
    
    bt(0, 0);
    
    if (Flag) {
        cout << result_a << " + " << result_b << endl;
    } else {
        cout << "-1" << endl;
    }
    return 0;
}