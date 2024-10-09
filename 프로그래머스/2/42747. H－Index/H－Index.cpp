#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int bisect(vector <int> list,int target){
    int start,end,mid;
    start=0;
    end=list.size()-1;
    while (start<=end){
        mid=(start+end)/2;
        if(list[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }   
    }
    return start;
}
int solution(vector<int> citations) {
    sort(citations.begin(),citations.end());
    int l=citations.size();
    int answer = 0;
    int idx=0;
    for (int i=0;i<1001;i++){
        idx=bisect(citations,i);
        if(l-idx>=i)answer=i;
    }
    return answer;
}