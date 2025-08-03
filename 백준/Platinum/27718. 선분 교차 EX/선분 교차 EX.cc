#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define rep(i,a,b) for(LL i=(a);i<(b);++i)
#define LL long long
using namespace std;

struct Point {
    LL x, y;
    Point() {}
    Point(LL x, LL y) : x(x), y(y) {}
    bool operator<(const Point b) const {
        if (x != b.x) {
            return x < b.x;
        }
        else {
            return y < b.y;
        }
    }
    bool operator==(const Point b) const {
        return x == b.x && y == b.y;
    }
    bool operator!=(const Point b) const {
        return !(*this == b);
    }
};

struct Segment {
    Point p1, p2;
    Segment(Point a, Point b) : p1(a), p2(b) {}
};

pair<LL, LL> makeVector(Point a, Point b) {
    return{ b.x - a.x, b.y - a.y };
}

LL dotProduct(pair<LL, LL> a, pair<LL, LL> b) {
    return a.first * b.first + a.second * b.second;
}

LL ccw(Point a, Point b, Point c) {
    pair<LL, LL> p1 = makeVector(a, b);
    pair<LL, LL> p2 = makeVector(a, c);
    LL cross = p1.first * p2.second - p1.second * p2.first;
    if (cross > 0) return 1;
    if (cross < 0) return -1;
    return 0;
}

LL crossProduct(Point a, Point b, Point c) {
    pair<LL, LL> p1 = makeVector(a, b);
    pair<LL, LL> p2 = makeVector(a, c);
    return p1.first * p2.second - p1.second * p2.first;
}

bool isOnSegment(Point p, Segment s) {
    if (ccw(s.p1, s.p2, p) != 0) return false;
    return min(s.p1.x, s.p2.x) <= p.x && p.x <= max(s.p1.x, s.p2.x) &&
        min(s.p1.y, s.p2.y) <= p.y && p.y <= max(s.p1.y, s.p2.y);
}

int classifyRelation(Segment s1, Segment s2) {
    if ((s1.p1 == s2.p1 && s1.p2 == s2.p2) || (s1.p1 == s2.p2 && s1.p2 == s2.p1)) {
        return 3;
    }

    LL c1 = ccw(s1.p1, s1.p2, s2.p1);
    LL c2 = ccw(s1.p1, s1.p2, s2.p2);
    LL c3 = ccw(s2.p1, s2.p2, s1.p1);
    LL c4 = ccw(s2.p1, s2.p2, s1.p2);

    if (c1 == 0 && c2 == 0) {
        bool s2p1_on_s1 = isOnSegment(s2.p1, s1);
        bool s2p2_on_s1 = isOnSegment(s2.p2, s1);
        bool s1p1_on_s2 = isOnSegment(s1.p1, s2);
        bool s1p2_on_s2 = isOnSegment(s1.p2, s2);

        if (s2p1_on_s1 || s2p2_on_s1 || s1p1_on_s2 || s1p2_on_s2) {
            int contact_points = 0;
            if (s1.p1 == s2.p1 || s1.p1 == s2.p2) contact_points++;
            if (s1.p2 == s2.p1 || s1.p2 == s2.p2) contact_points++;

            bool internal_contact = false;
            if (s2p1_on_s1 && s2.p1 != s1.p1 && s2.p1 != s1.p2) internal_contact = true;
            if (s2p2_on_s1 && s2.p2 != s1.p1 && s2.p2 != s1.p2) internal_contact = true;
            if (s1p1_on_s2 && s1.p1 != s2.p1 && s1.p1 != s2.p2) internal_contact = true;
            if (s1p2_on_s2 && s1.p2 != s2.p1 && s1.p2 != s2.p2) internal_contact = true;

            if (internal_contact) {
                return 3; // 겹치는 구간이 있음
            }
            else if (contact_points == 1) {
                return 1; // 끝점에서만 만남
            }
            else {
                return 3; // 겹치는 구간이 있음
            }
        }

        return 0; // 교점 없음
    }

    if (((c1 * c2) <= 0) && ((c3 * c4) <= 0)) {
        bool isEndpoint = false;

        if (c1 == 0 && isOnSegment(s2.p1, s1)) isEndpoint = true;
        if (c2 == 0 && isOnSegment(s2.p2, s1)) isEndpoint = true;
        if (c3 == 0 && isOnSegment(s1.p1, s2)) isEndpoint = true;
        if (c4 == 0 && isOnSegment(s1.p2, s2)) isEndpoint = true;

        if (isEndpoint) {
            return 1; // 끝점에서 만남
        }
        else {
            return 2; // 내부에서 만남
        }
    }

    return 0; // 교점 없음
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;

    vector<Segment> segments;
    for (int i = 0; i < N; i++) {
        LL x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        segments.push_back(Segment(Point(x1, y1), Point(x2, y2)));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << classifyRelation(segments[i], segments[j]);
        }
        cout << '\n';
    }

    return 0;
}