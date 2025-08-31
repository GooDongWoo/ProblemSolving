#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define rep(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

struct Point {
    int x, y;
};

long long ccw(Point p1, Point p2, Point p3) {
    return 1LL * (p2.x - p1.x) * (p3.y - p1.y) - 1LL * (p2.y - p1.y) * (p3.x - p1.x);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pair<Point, bool>> all_people;
    vector<Point> lovelyz_fans;
    
    rep(i, 0, n) {
        Point p;
        string name;
        cin >> p.x >> p.y >> name;

        bool is_lovelyz = (name == "LOVELYZ");
        all_people.push_back({p, is_lovelyz});

        if (is_lovelyz) {
            lovelyz_fans.push_back(p);
        }
    }

    int max_positive_count = 0;
    int lovelyz_fan_count = lovelyz_fans.size();

    rep(i, 0, n - 1) {
        rep(j, i + 1, n) {
            Point p1 = all_people[i].first;
            Point p2 = all_people[j].first;

            vector<bool> group[2];
            int offset = 0;
            
            rep(k, 0, n) {
                Point current_person_point = all_people[k].first;
                
                if ((current_person_point.x == p1.x && current_person_point.y == p1.y) ||
                    (current_person_point.x == p2.x && current_person_point.y == p2.y)) {
                    offset += all_people[k].second;
                    continue;
                }

                long long pos = ccw(p1, p2, current_person_point);

                if (pos > 0) {
                    group[0].push_back(all_people[k].second);
                } else if (pos < 0) {
                    group[1].push_back(all_people[k].second);
                }
            }
            rep(step, 0, 2){
                bool is_all_lovelyz = true;
                for (bool is_fan : group[step]) {
                    if (!is_fan) {
                        is_all_lovelyz = false;
                        break;
                    }
                }

                if (is_all_lovelyz) {
                    int current_count = group[step].size() + offset;
                    if (current_count > max_positive_count) {
                        max_positive_count = current_count;
                    }
                }
            }
        }
    }

    cout << max_positive_count;

    return 0;
}