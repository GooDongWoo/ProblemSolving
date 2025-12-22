#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

const double PI = acos(-1);

struct Point {
    double x, y, z;
};

vector<vector<pair<int, double>>> adj;
int farthest_node;
double max_dist;

Point get_coordinate(int lat, string ns, int lon, string ew) {
    double theta, phi;

    if (ns == "S") theta = (90.0 + lat) / 180.0 * PI;
    else theta = (90.0 - lat) / 180.0 * PI;

    if (ew == "W") phi = (180.0 - lon) / 180.0 * PI;
    else phi = (180.0 + lon) / 180.0 * PI;

    double z = cos(theta);
    double y = sin(theta) * sin(phi);
    double x = sin(theta) * cos(phi);

    return {x, y, z};
}

double get_dist(const Point& p1, const Point& p2) {
    double dist_sq = (p1.x - p2.x)*(p1.x - p2.x) + 
                     (p1.y - p2.y)*(p1.y - p2.y) + 
                     (p1.z - p2.z)*(p1.z - p2.z);
    
    double val = (2.0 - dist_sq) / 2.0;
    if (val > 1.0) val = 1.0;
    if (val < -1.0) val = -1.0;
    
    return acos(val);
}

void dfs(int cur, int p, double current_w) {
    if (current_w > max_dist) {
        max_dist = current_w;
        farthest_node = cur;
    }

    for (auto& edge : adj[cur]) {
        int next_node = edge.first;
        double weight = edge.second;

        if (next_node != p) {
            dfs(next_node, cur, current_w + weight);
        }
    }
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    map<string, int> name_to_id;
    vector<string> id_to_name(n);
    vector<Point> coords(n);
    
    adj.assign(n, vector<pair<int, double>>());

    for (int i = 0; i < n; ++i) {
        string name, ns, ew;
        int lat, lon;
        cin >> name >> lat >> ns >> lon >> ew;

        coords[i] = get_coordinate(lat, ns, lon, ew);
        name_to_id[name] = i;
        id_to_name[i] = name;
    }

    for (int i = 0; i < n - 1; ++i) {
        string u_str, v_str;
        cin >> u_str >> v_str;
        
        int u = name_to_id[u_str];
        int v = name_to_id[v_str];
        
        double w = get_dist(coords[u], coords[v]);
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    max_dist = -1.0;
    farthest_node = 0;
    dfs(0, -1, 0.0);
    int start_node = farthest_node;

    max_dist = -1.0;
    farthest_node = start_node;
    dfs(start_node, -1, 0.0);
    int end_node = farthest_node;

    if (id_to_name[start_node] < id_to_name[end_node]) {
        cout << id_to_name[start_node] << " " << id_to_name[end_node] << "\n";
    } else {
        cout << id_to_name[end_node] << " " << id_to_name[start_node] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}