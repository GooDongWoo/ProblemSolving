#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    printf("%d\n", abs(a + d - (b + c)));
    return 0;
}