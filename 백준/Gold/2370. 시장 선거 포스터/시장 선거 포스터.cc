#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

#define rep(i, a, b) for (int i=a;i<b;++i)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> posters(n);
    vector<int> coords;

    rep(i, 0, n) {
        int l, r;
        cin >> l >> r;
        posters[i] = { l, r };
        coords.push_back(l);
        coords.push_back(r);
    }
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    // 원본 좌표를 압축된 좌표로 매핑
    map<int, int> coord_map;
    rep(i, 0, coords.size()) {
        coord_map[coords[i]] = i;
    }
    vector<int> wall(coords.size(), 0);
    rep(i, 0, n) {
        int l = coord_map[posters[i].first];
        int r = coord_map[posters[i].second];
        rep(j, l, r+1) wall[j] = i + 1;
    }

    // 보이는 포스터 카운트
    set<int> visible_posters;
    for (int id : wall) {
        if (id > 0) visible_posters.insert(id);
    }
    cout << visible_posters.size();

    return 0;
}