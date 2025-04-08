#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define LL long long
using namespace std;

int N;
LL T;
int P[3][10000], t[3][10000];
vector<pair<int, LL>> compressed[3]; // (score, time) pairs

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> T;

    rep(i, 0, 3)
        rep(j, 0, N)
        cin >> P[i][j];

    rep(i, 0, 3)
        rep(j, 0, N)
        cin >> t[i][j];

    rep(i, 0, 3) {
        LL totalTime = 0;
        int totalScore = 0;
        compressed[i].push_back({ 0, 0 });
        rep(j, 0, N) {
            totalTime += t[i][j];
            totalScore += P[i][j];
            if (totalScore > compressed[i].back().first) {
                compressed[i].push_back({ totalScore, totalTime });
            }
        }
    }

    int maxScore = 0;
    for (auto& p0 : compressed[0]) {
        int score0 = p0.first;
        LL time0 = p0.second;
        LL remainingTime = T - time0;

        if (time0 > T) 
            continue;
        
        for (auto& p1 : compressed[1]) {
            int score1 = p1.first;
            LL time1 = p1.second;

            if (time1 > remainingTime) 
                continue;

            LL finalRemainingTime = remainingTime - time1;
            int left = 0, right = compressed[2].size() - 1;
            int bestIdx = 0;

            while (left <= right) {
                int mid = (left + right) / 2;

                if (compressed[2][mid].second <= finalRemainingTime) {
                    bestIdx = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }

            int score2 = compressed[2][bestIdx].first;
            maxScore = max(maxScore, score0 + score1 + score2);
        }
    }

    cout << maxScore << endl;
    return 0;
}