#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N; cin>>N;
    vector<ll> A(N);
    for (int i=0; i<N; i++) cin>>A[i];

    vector<ll> psum(N+1);
    vector<ll> pssum(N+1);
    for (int i=0; i<N; i++) psum[i+1] = psum[i] + A[i];
    for (int i=0; i<N; i++) pssum[i+1] = pssum[i] + A[i]*A[i];

    ll maxmul = 0;
    for (int k=0; k<N; k++) {
        ll l = psum[N] - psum[k];
        ll r = pssum[k] - pssum[0];
        maxmul = max(maxmul, l*r);
    }
    cout<<maxmul<<endl;
}