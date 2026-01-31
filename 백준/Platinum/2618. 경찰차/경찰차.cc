#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int N, W;
pair<int, int> events[1002];
int dp[1002][1002];
int choice[1002][1002];

int get_dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int i, int j) {
    int next_event = max(i, j) + 1;
    if (next_event > W) return 0;

    int& ret = dp[i][j];
    if (ret != -1) return ret;

    pair<int, int> pos1 = (i == 0) ? make_pair(1, 1) : events[i];
    int dist1 = get_dist(pos1, events[next_event]) + solve(next_event, j);

    pair<int, int> pos2 = (j == 0) ? make_pair(N, N) : events[j];
    int dist2 = get_dist(pos2, events[next_event]) + solve(i, next_event);

    if (dist1 < dist2) {
        choice[i][j] = 1;
        return ret = dist1;
    } else {
        choice[i][j] = 2;
        return ret = dist2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> W;
    for (int i = 1; i <= W; i++) {
        cin >> events[i].first >> events[i].second;
    }

    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0) << "\n";

    int p1 = 0, p2 = 0;
    for (int i = 1; i <= W; i++) {
        cout << choice[p1][p2] << "\n";
        if (choice[p1][p2] == 1) p1 = i;
        else p2 = i;
    }

    return 0;
}