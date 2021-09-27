#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve() {
    int N; cin>>N;
    vector<ll> V(N);
    for (int i=0; i<N; i++) {
        cin>>V[i];
    }
    sort(V.begin(), V.end());
    ll res = -987654321;
    res = max(res, V[N-1] * V[N-2] * V[N-3]);
    res = max(res, V[N-1] * V[N-2]);
    res = max(res, V[N-1] * V[0] * V[1]);
    res = max(res, V[0] * V[1]);
    cout<<res<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}