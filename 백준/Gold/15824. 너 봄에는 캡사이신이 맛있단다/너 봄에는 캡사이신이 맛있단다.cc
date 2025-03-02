#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define LL long long
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MOD 1000000007

// 거듭제곱 계산 (빠른 거듭제곱 알고리즘)
LL power(LL base, LL exp) {
    LL result = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

int main() {
    fastio;
    LL N;
    cin >> N;
    
    vector<LL> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    if (N == 1) {
        cout << "0" << endl;
        return 0;
    }
    
    sort(arr.begin(), arr.end());
    
    LL ans = 0;
    
    // 각 원소의 기여도 계산
    for (int i = 0; i < N; i++) {
        // i번째 원소가 최댓값이 되는 경우 (2^i 개의 부분집합에서)
        LL max_contribution = (arr[i] % MOD * power(2, i) % MOD) % MOD;
        
        // i번째 원소가 최솟값이 되는 경우 (2^(N-1-i) 개의 부분집합에서)
        LL min_contribution = (arr[i] % MOD * power(2, N-1-i) % MOD) % MOD;
        
        // 최댓값 기여도 - 최솟값 기여도
        ans = (ans + max_contribution - min_contribution + MOD) % MOD;
    }
    
    cout << ans << endl;
    return 0;
}