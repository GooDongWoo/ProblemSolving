#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, m, target;
        bool flag = 1;
        cin >>n >> m;
        int nm = m;
        for(int i=0;i<n;i++){
        	if((nm % 2) != 1) flag = 0;
            nm /= 2;
        }
        if(flag)printf("#%d ON\n", test_case);
        else printf("#%d OFF\n", test_case);


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}