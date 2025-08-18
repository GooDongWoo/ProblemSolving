#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct Point {
    double x, y, z;
};

double distance(Point p1, Point p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) +
                     std::pow(p1.y - p2.y, 2) +
                     std::pow(p1.z - p2.z, 2));
}

double total_distance(Point p, const std::vector<Point>& sources) {
    double sum = 0.0;
    for (const auto& source : sources) {
        sum += distance(p, source);
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<Point> sources(3);
    Point centroid = {0.0, 0.0, 0.0};

    for (int i = 0; i < 3; ++i) {
        std::cin >> sources[i].x >> sources[i].y >> sources[i].z;
        centroid.x += sources[i].x;
        centroid.y += sources[i].y;
        centroid.z += sources[i].z;
    }
    centroid.x /= 3.0;
    centroid.y /= 3.0;
    centroid.z /= 3.0;

    Point current_p = centroid;
    double alpha = 2e9;
    double decay_rate = 0.999;
    
    for (int i = 0; i < 500000; ++i) {
        Point gradient = {0.0, 0.0, 0.0};

        for (const auto& source : sources) {
            double dist = distance(current_p, source);
            if (dist > 1e-9) { 
                gradient.x += (current_p.x - source.x) / dist;
                gradient.y += (current_p.y - source.y) / dist;
                gradient.z += (current_p.z - source.z) / dist;
            }
        }
        
        current_p.x -= alpha * gradient.x;
        current_p.y -= alpha * gradient.y;
        current_p.z -= alpha * gradient.z;

        alpha *= decay_rate;
    }

    double min_dist_sum = total_distance(current_p, sources);
    std::cout << std::fixed << std::setprecision(8) << min_dist_sum << std::endl;

    return 0;
}