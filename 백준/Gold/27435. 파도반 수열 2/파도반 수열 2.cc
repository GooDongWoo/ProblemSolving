#include <iostream>
#include <vector>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define LL long long
using namespace std;
const LL MOD = 998244353;

LL arr[6] = { 0, 1, 1, 1, 2, 2 };

vector<vector<LL>> bmat(5, vector<LL>(5, 0));

vector<vector<LL>> matmul(const vector<vector<LL>>& m1, const vector<vector<LL>>& m2) {
    vector<vector<LL>> res(5, vector<LL>(5, 0));
    rep(i, 0, 5)
        rep(j, 0, 5)
        rep(k, 0, 5) {
        res[i][j] = (res[i][j] + (m1[i][k] * m2[k][j]) % MOD) % MOD;
    }
    return res;
}

vector<vector<LL>> matrix_power(LL num) {
    if (num <= 1)
        return bmat;

    vector<vector<LL>> half = matrix_power(num / 2);
    vector<vector<LL>> result = matmul(half, half);

    if (num & 1) {
        result = matmul(result, bmat);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bmat = {
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0}
    };

    int T;
    cin >> T;

    while (T--) {
        LL N;
        cin >> N;

        if (N <= 5) {
            cout << arr[N] << "\n";
            continue;
        }
        vector<vector<LL>> result_matrix = matrix_power(N - 5);

        LL ans = 0;
        rep(i, 0, 5) {
            ans = (ans + (result_matrix[0][i] * arr[5 - i]) % MOD) % MOD;
        }

        cout << ans << "\n";
    }

    return 0;
}