#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve() {
    int N, W; cin>>N>>W;
    vector<ll> v(N);
    vector<bool> rising(N);
    for (int i=0; i<N; i++) {
        cin>>v[i];
    }
    for (int i=0; i<N-1; i++) {
        if (v[i+1] > v[i]) rising[i] = true;
        else rising[i] = false;
    }
    rising[N-1] = false;
    bool last = false;
    ll m = W;
    ll coin = 0;
    for (int i=0; i<N; i++) {
        if (last == false) {
            if (rising[i] == true) {
                coin += m/v[i];
                m = m%v[i];
            }
        } else {
            if (rising[i] == false) {
                m += coin*v[i];
                coin = 0;
            } else {
                coin += m/v[i];
                m = m%v[i];
            }
        }
        last = rising[i];
    }
    cout<<m<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}