#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;
    string roman_numerals[13];
    roman_numerals[1] = "I";
    roman_numerals[2] = "II";
    roman_numerals[3] = "III";
    roman_numerals[4] = "IV";
    roman_numerals[5] = "V";
    roman_numerals[6] = "VI";
    roman_numerals[7] = "VII";
    roman_numerals[8] = "VIII";
    roman_numerals[9] = "IX";
    roman_numerals[10] = "X";
    roman_numerals[11] = "XI";
    roman_numerals[12] = "XII";

    vector<int> found_numbers;

    for (int i = 1; i <= 12; ++i) {
        if (s.find(roman_numerals[i]) != string::npos) {
            found_numbers.push_back(i);
        }
    }

    for (size_t i = 0; i < found_numbers.size(); ++i) {
        cout << found_numbers[i];
        if (i < found_numbers.size() - 1) {
            cout << " ";
        }
    }
    cout << "\n";

    return 0;
}