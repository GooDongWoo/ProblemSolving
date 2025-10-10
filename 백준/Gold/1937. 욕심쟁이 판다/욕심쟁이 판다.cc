#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i, a, b) for (int i = a; i < b; ++i)
using LL = long long;
using namespace std;

int N, mat[500][500], dp[500][500], ans;
int dys[] = { 1, 0, -1, 0 };
int dxs[] = { 0, 1, 0, -1 };

int dfs(int cy, int cx, int bef)
{
    dp[cy][cx] = 1;
    rep(step, 0, 4)
    {
        int ny = cy + dys[step];
        int nx = cx + dxs[step];
        if (!(0 <= ny && ny < N && 0 <= nx && nx < N) || mat[ny][nx] <= mat[cy][cx])
            continue;
        if (dp[ny][nx] == 0)
            dp[cy][cx] = max(dp[cy][cx], dfs(ny, nx, bef + 1) + 1);
        else
            dp[cy][cx] = max(dp[cy][cx], dp[ny][nx] + 1);
    }
    return dp[cy][cx];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin >> N;
    rep(i, 0, N)
    {
        rep(j, 0, N)
        {
            cin >> mat[i][j];
        }
    }
    rep(i, 0, N)
    {
        rep(j, 0, N)
        {
            if (dp[i][j])
            {
                continue;
            }
            ans = max(ans, dfs(i, j, 0));
        }
    }
    cout << ans;
}