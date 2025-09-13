#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <tuple>

#define rep(i, a, b) for(int i = a; i < b; ++i)
using namespace std;

struct Sensor {
    long long x, y, r;
};

struct Edge {
    double cost;
    int u, v;

    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

vector<int> parent;

int findSet(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = findSet(parent[v]);
}

void uniteSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b)
        parent[b] = a;
}

double dist(const Sensor& s1, const Sensor& s2) {
    long long dx = s1.x - s2.x;
    long long dy = s1.y - s2.y;
    return sqrt((double)dx * dx + (double)dy * dy);
}

void solve() {
    int w, n;
    cin >> w >> n;

    if (n == 0) {
        cout << (double)w / 2.0 << "\n";
        return;
    }
    
    vector<Sensor> sensors(n);
    rep(i, 0, n) {
        cin >> sensors[i].x >> sensors[i].y >> sensors[i].r;
    }

    parent.assign(n + 2, 0);
    rep(i, 0, n + 2) {
        parent[i] = i;
    }
    
    vector<Edge> edges;

    rep(i, 0, n) {
        edges.push_back({(double)sensors[i].x - sensors[i].r, i, n});
        edges.push_back({(double)w - sensors[i].x - sensors[i].r, i, n + 1});
    }

    rep(i, 0, n) {
        rep(j, i + 1, n) {
            double d = dist(sensors[i], sensors[j]);
            double clearance = d - sensors[i].r - sensors[j].r;
            edges.push_back({clearance, i, j});
        }
    }
    
    sort(edges.begin(), edges.end());

    double maxDiameter = 0;

    for (const auto& edge : edges) {
        if (findSet(edge.u) != findSet(edge.v)) {
            uniteSets(edge.u, edge.v);
            if (findSet(n) == findSet(n + 1)) {
                maxDiameter = max(0.0, edge.cost);
                break;
            }
        }
    }
    
    if (findSet(n) != findSet(n+1)) {
        maxDiameter = w;
    }

    cout << maxDiameter / 2.0 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed;
    cout.precision(6);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}