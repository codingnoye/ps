#include <bits/stdc++.h>
#define ff(i, s, e) for (int i=s; i<e; i++)
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    
    int T; cin>>T;
    ff(C, 1, T+1) {
        int N; cin>>N;
        vector<pair<ll, ll>> v(N);

        vector<ll> comp_inv(N);

        ff(i, 0, N) {
            ll x; cin>>x;
            comp_inv[i] = x;
        }
        ff(i, 0, N) {
            ll x; cin>>x;
            v[i] = {x, i};
        }

        sort(v.begin(), v.end());

        ll ans = 0;
        ff(i, 0, N) {
            ans += abs(comp_inv[v[i].second] - comp_inv[i]);
        }
        cout<<"Case #"<<C<<endl<<ans<<endl;
    }
}