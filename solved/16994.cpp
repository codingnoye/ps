#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#ifdef ONLINE_JUDGE
    #define endl '\n'
#endif
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
using namespace std;
typedef long long ll;

#include <ext/rope>
using namespace __gnu_cxx;

int main() {
    fastio;
    
    crope R; string S; cin>>S;
    R.append(S.c_str());
    
    int Q; cin>>Q;

    int L = sz(S);

    while (Q--) {
        int t; cin>>t;
        if (t==1) {
            int x, y; cin>>x>>y;
            R = R.substr(x, y+1-x) + R.substr(0, x) + R.substr(y+1, L-(y+1));
        } else if (t==2) {
            int x, y; cin>>x>>y;
            R = R.substr(0, x) + R.substr(y+1, L-(y+1)) + R.substr(x, y+1-x);
        } else if (t==3) {
            int x; cin>>x;
            cout<<R.at(x)<<endl;
        }
    }
}