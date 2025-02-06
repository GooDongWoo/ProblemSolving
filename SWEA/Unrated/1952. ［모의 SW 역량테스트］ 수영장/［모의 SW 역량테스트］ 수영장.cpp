#include<iostream>
#include <vector>
#include <utility>

#define rep(i,a,b) for(int i=a;i<b;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0)

using namespace std;

int p[4], arr[13], dp[13];

int main(int argc, char** argv)
{
	fastio;
    int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case) {
        rep(i,0,4) cin >> p[i];
        rep(i,1,13) cin >> arr[i];
        fill(dp, dp+13, p[3]);dp[0] = 0;
        rep(i,1,13){
        	dp[i] = min(dp[i], dp[i-1]+(arr[i] * p[0]));
            dp[i] = min(dp[i], dp[i-1]+p[1]);
            if(i >= 3){
            	dp[i] = min(dp[i], dp[i-3] + p[2]);
            }
        }
        printf("#%d %d\n",test_case, dp[12]);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}