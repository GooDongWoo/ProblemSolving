#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define LL long long
using namespace std;
const int DAY = 1440;
int N, K, arr[3][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    rep(i, 0, 3)
        rep(j, 0, 2)
        cin >> arr[i][j];
    bool Flag = true;
    int start = arr[0][1];
    rep(day, 1, N + 1) {
        rep(time, 0, 3) {
            if (arr[time][0] <= start) {
                if (start > arr[time][1]) {
                    start = arr[time][1];
                }
                start += K;
            }
            else {
                Flag = 0;
                break;
            }
        }
        start -= DAY;
        if (!Flag) {
            break;
        }
    }
    if (Flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}