#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ff(i, s, e) for (int i=s; i<e; i++)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        ll N, K; cin>>N>>K;
        vector<pair<ll, ll>> A(N);
        
        ll maxv = 0;
        for (ll i=0; i<N; i++) {
            ll x; cin>>x;
            A[i] = {max(0LL, K-x), i};
            maxv = max(maxv, max(0LL, K-x));
        }
        sort(A.begin(), A.end(), greater<pair<ll, ll>>());
        
        ll cost = 0;
        ll last = -1;
        ll minrange=9999999; ll maxrange=-1;
        for (int i=0; i<N; i++) {
            auto [v, org_idx] = A[i];
            if (v != last && last != -1) {
                ll c = (last - v) * (maxrange - minrange);
                // cout<<"[ "<<minrange<<" "<<maxrange<<" ] "<<c<<endl;
                cost += c;
            }
            minrange = min(minrange, org_idx);
            maxrange = max(maxrange, org_idx+1);
            last = v;
        }
        if (last != 0) {
            cost += last * (maxrange - minrange);
        }
        cout<<"Case #"<<t<<endl;
        cout<<maxv<<' '<<cost<<endl;
    }
}