#include <iostream>
#include <algorithm>

#define rep(i,a,b) for(int (i)=(a);i<(b);++(i))

using namespace std;

int N, arr[8][2], ans;

// cnt: 현재까지 깨진 계란의 수
void bt(int idx, int cnt) {
    if (idx == N) {
        ans = max(ans, cnt);
        return;
    }

    if (arr[idx][0] <= 0 || cnt == N - 1) {
        bt(idx + 1, cnt);
        return;
    }

    rep(i, 0, N) {
        if (i == idx || arr[i][0] <= 0) continue;

        arr[i][0] -= arr[idx][1];
        arr[idx][0] -= arr[i][1];

        int broken = 0;
        if (arr[idx][0] <= 0) broken++;
        if (arr[i][0] <= 0) broken++;

        bt(idx + 1, cnt + broken);

        arr[idx][0] += arr[i][1];
        arr[i][0] += arr[idx][1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return 0;
    rep(i, 0, N) {
        cin >> arr[i][0] >> arr[i][1];
    }

    bt(0, 0);
    cout << ans;

    return 0;
}