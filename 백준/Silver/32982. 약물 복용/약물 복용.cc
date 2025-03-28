#include <iostream>
using namespace std;

const int DAY = 1440; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    int mealWindows[3][2]; // [meal][start/end]
    for (int i = 0; i < 3; i++) {
        cin >> mealWindows[i][0] >> mealWindows[i][1];
    }

    int medicationTime = mealWindows[0][1];
    bool possible = true;

    for (int day = 0; day < N; day++) {
        int startMeal = (day == 0) ? 1 : 0;

        for (int meal = startMeal; meal < 3; meal++) {
            int mealStart = mealWindows[meal][0] + day * DAY;
            int mealEnd = mealWindows[meal][1] + day * DAY;

            if (medicationTime + K < mealStart) {
                possible = false;
                break;
            }

            medicationTime = min(mealEnd, max(mealStart, medicationTime + K));
        }

        if (!possible) break;
    }

    cout << (possible ? "YES" : "NO") << endl;

    return 0;
}