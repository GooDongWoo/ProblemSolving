#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;vector<int> tmp=array;
    int a,b,c;
    for (int i=0;i<commands.size();i++){
        a=commands[i][0]-1;b=commands[i][1];c=commands[i][2]-1;
        for (int j=0;j<array.size();j++){
            tmp[j]=array[j];
        }
        sort(tmp.begin()+a,tmp.begin()+b);
        answer.push_back(tmp[a+c]);
    }
    
    return answer;
}