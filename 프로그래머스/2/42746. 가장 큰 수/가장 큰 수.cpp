#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(string a, string b) {
    return a + b > b + a;  // 두 문자열을 이어붙여서 비교
}
string solution(vector<int> numbers) {
    vector <string> tmp;string answer = "";
    for (int i=0;i<numbers.size();i++){
        tmp.push_back(to_string(numbers[i]));
    }
    sort(tmp.begin(),tmp.end(),cmp);
    for (int i=0;i<numbers.size();i++){
        answer+=tmp[i];
    }
    if(answer[0]=='0')
        return "0";
    return answer;
}