#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string name;
    while (cin >> name && name != ".") {
        int N = name.size();
        bool found = false;

        for (int i = 1; i <= N / 2; ++i) {
            if (N % i == 0) {
                string pattern = name.substr(0, i);
                bool valid = true;

                for (int j = i; j < N; j += i) {
                    if (name.substr(j, i) != pattern) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    cout << N / i << '\n';
                    found = true;
                    break;
                }
            }
        }

        if (!found) cout << 1 << '\n';
    }
    return 0;
}