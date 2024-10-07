#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    map<int,int> s;
    for(int i : nums)
    {
        s[i]=1;
    }
    int n=nums.size()/2;
    int answer = (n<s.size()) ? n: s.size();
    return answer;
}