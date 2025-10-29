#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, K;
    string word;
    cin >> N >> K >> word;
    
    string result = "";
    int toRemove = K;
    
    for (int i = 0; i < N; i++) {
        while (!result.empty() && result.back() < word[i] && toRemove > 0) {
            result.pop_back();
            toRemove--;
        }
        result.push_back(word[i]);
    }
    
    while (toRemove > 0) {
        result.pop_back();
        toRemove--;
    }
    
    cout << result << '\n';
    return 0;
}