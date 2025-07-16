#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string input;
    cin >> input;
    long long denominator = 1;
    for (int i = 0; i < input.length() - 2; i++) {
        denominator *= 10;
    }

    string numerator_str = input.substr(2);
    long long numerator = 0;
    for (char c : numerator_str) {
        numerator = numerator * 10 + (c - '0');
    }

    long long g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;

    cout << "YES\n" << numerator << " " << denominator << "\n";

    return 0;
}