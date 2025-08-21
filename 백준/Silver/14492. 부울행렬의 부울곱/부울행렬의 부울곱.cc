#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

int N, arr1[300][300], arr2[300][300], ans;
LL rows[300][5], cols[300][5]; // 5개의 64비트 청크로 분할

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    
    rep(i, 0, N) {
        rep(j, 0, N) {
            cin >> arr1[i][j];
            if (arr1[i][j]) {
                rows[i][j/64] |= (1LL << (j%64));
            }
        }
    }
    
    rep(i, 0, N) {
        rep(j, 0, N) {
            cin >> arr2[i][j];
            if (arr2[i][j]) {
                cols[j][i/64] |= (1LL << (i%64));
            }
        }
    }
    
    rep(i, 0, N) {
        rep(j, 0, N) {
            bool found = false;
            rep(chunk, 0, 5) {
                if (rows[i][chunk] & cols[j][chunk]) {
                    found = true;
                    break;
                }
            }
            if (found) ans++;
        }
    }
    
    cout << ans;
    return 0;
}