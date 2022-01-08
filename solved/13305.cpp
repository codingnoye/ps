#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve() {
    int N; cin>>N;
    vector<ll> E(N-1);
    vector<ll> V(N);
    for (int i=0; i<N-1; i++) {
        cin>>E[i];
    }
    for (int i=0; i<N; i++) {
        cin>>V[i];
    }
    ll now = V[0];
    ll ans = 0;
    for (int i=0; i<N-1; i++) {
        if (now > V[i]) now = V[i];
        ans += E[i]*now;
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}