#include <iostream>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T; 
    std::cin >> T;

    int km_per_candy[4] = {0, 1, 3, 5};

    while (T--) {
        int G, C, E;
        std::cin >> G >> C >> E;
        int candies_needed = std::max(0, E - C);
        int total_km = candies_needed * km_per_candy[G];
        std::cout << total_km << "\n";
    }

    return 0;
}