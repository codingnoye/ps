#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#ifdef ONLINE_JUDGE
    #define endl '\n'
#endif
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    ll N; cin>>N;
    ll i = 1;
    ll now = 0;
    while (true) {
        now += i;
        
        if (N < now) break;

        i++;
    }
    cout<<i-1<<endl;
}