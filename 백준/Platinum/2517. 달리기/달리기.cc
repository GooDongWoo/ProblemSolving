#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;

int N;
int bit[500001];
int initial_skills[500001];
vector<int> coords;

void update(int idx, int val) {
    while (idx <= N) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int cur = 0;
    while (idx > 0) {
        cur += bit[idx];
        idx -= idx & -idx;
    }
    return cur;
}

int get_coord(int val) {
    return lower_bound(coords.begin(), coords.end(), val) - coords.begin() + 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;
    coords.reserve(N);
    rep(i, 1, N + 1) {
        cin >> initial_skills[i];
        coords.push_back(initial_skills[i]);
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    rep(i, 1, N + 1) {
        int compressed_idx = get_coord(initial_skills[i]);
        int count_le = query(compressed_idx);
        cout << (i - count_le) << '\n';
        update(compressed_idx, 1);
    }

    return 0;
}