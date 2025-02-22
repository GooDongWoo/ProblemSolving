#define _CRT_SECURE_NO_WARNINGS
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)
#define rep(i, a, b) for (int i=a;i<b;++i)
#define fi first
#define se second
#define LL long long
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <numeric>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
    fastio;
    string word, a, b;
    cin >> word;
    if (word.size() >= 3) {
        if (word.size() == 3) {
            int idx = word.find('0');
            if (idx == 1) {
                printf("%d\n",10+ word[2] - '0');
            }
            else {
                printf("%d\n", 10 + word[0] - '0');
            }
        }
        else {
            printf("20\n");
        }
    }
    else {
        printf("%d\n", word[0]-'0' + word[1] - '0');
    }
    return 0;
}