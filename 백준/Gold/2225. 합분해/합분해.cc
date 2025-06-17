#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<vector<long long>> dp(K + 1, vector<long long>(N + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= K; i++) {
        vector<long long> prefix(N + 2, 0);

        for (int j = 0; j <= N; j++) {
            prefix[j + 1] = (prefix[j] + dp[i-1][j]) % MOD;
        }

        for (int j = 0; j <= N; j++) {
            // j에서 사용할 수 있는 수의 범위: 0 ~ min(j, N)
            int left = max(0, j - N);
            int right = j;
            dp[i][j] = (prefix[right + 1] - prefix[left] + MOD) % MOD;
        }
    }

    cout << dp[K][N] << endl;
    return 0;
}