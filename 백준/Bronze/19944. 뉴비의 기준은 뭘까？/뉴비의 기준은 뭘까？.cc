#include <iostream>

using namespace std;

int N, M;

int main(){
    cin >> N >> M;
    if(M == 1 || M == 2){
        printf("NEWBIE!");
    }
    else if (M <= N){
        printf("OLDBIE!");
    }
    else{
        printf("TLE!");
    }
    
}