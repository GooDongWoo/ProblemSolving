#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A;
vector<int> transfer_stations;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    A.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        if (i > 1 && i < N && A[i] == 1) {
            transfer_stations.push_back(i);
        }
    }

    if (N == 2) {
        cout << "mnx" << endl;
        return 0;
    }

    if (transfer_stations.empty()) {
        cout << "mnx" << endl;
        return 0;
    }

    vector<bool> is_winning_at_transfer(transfer_stations.size());

    bool next_point_is_win = false;

    for (int i = transfer_stations.size() - 1; i >= 0; --i) {
        int current_station_idx = transfer_stations[i];
        int next_station_idx = (i == transfer_stations.size() - 1) ? N : transfer_stations[i + 1];

        int normal_stations_count = next_station_idx - current_station_idx - 1;

        if (normal_stations_count == 0) {
            is_winning_at_transfer[i] = !next_point_is_win;
        }
        else {
            is_winning_at_transfer[i] = true;
        }
        next_point_is_win = is_winning_at_transfer[i];
    }

    int first_transfer_idx = transfer_stations[0];
    if (first_transfer_idx > 2) {
        cout << "mnx" << endl;
    }
    else {
        if (is_winning_at_transfer[0]) {
            cout << "alsdkffhgk" << endl; // 민아
        }
        else {
            cout << "mnx" << endl; // 세훈
        }
    }

    return 0;
}