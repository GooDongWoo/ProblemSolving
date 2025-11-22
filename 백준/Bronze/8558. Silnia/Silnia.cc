#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    if (std::cin >> n) {
        if (n == 0) {
            std::cout << 1 << "\n";
        } else if (n == 1) {
            std::cout << 1 << "\n";
        } else if (n == 2) {
            std::cout << 2 << "\n";
        } else if (n == 3) {
            std::cout << 6 << "\n";
        } else if (n == 4) {
            std::cout << 4 << "\n";
        } else {
            std::cout << 0 << "\n";
        }
    }
    return 0;
}