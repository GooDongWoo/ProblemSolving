#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector <int> l;
    l.push_back(arr[0]);
    for (int i=1;i<arr.size();i++){
        if(l.back()!=arr[i]){
            l.push_back(arr[i]);
        }
    }

    return l;
}