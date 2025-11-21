#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    int plan[1000];
    int real[1000];
    int cnt = 0;
    
    cin >>N;
    for(int i=0;i<N;i++){
        cin >> plan[i];
    }
    for(int i=0;i<N;i++){
        cin >> real[i];
    }
    for(int i=0;i<N;i++){
        if(plan[i]<=real[i])cnt++;
    }
    cout << cnt;
}