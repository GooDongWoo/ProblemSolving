#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(v) v.begin(), v.end()
#define comprseconds(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define IDX(v, x) (lower_bound(all(v), x) - v.begin())
#define INF 987654321
#define LLINF 987654321987654321LL
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }
int main(){
    fastio;
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        if(n<6) cout<<"-1\n";
        else if(n&1) cout<<4<<'\n'<<1<<" "<<3<<" "<<n-3<<" "<<n-2<<'\n';
        else cout<<3<<'\n'<<1<<" "<<n/2<<" "<<n/2+1<<'\n';
    }
}