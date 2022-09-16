#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N; cin>>N;
    ll allsum = 0;
    vector<ll> A(N);
    for (int i=0; i<N; i++) {
        cin>>A[i];
        allsum += A[i];
    }
    ll res = 0;
    for (int i=0; i<N; i++) {
        res += (allsum - A[i]) * A[i];
    }
    cout<<(res/2)<<endl;
}