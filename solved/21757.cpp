#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N; cin>>N;
    vector<ll> A(N);
    for(int i=0; i<N; i++) cin>>A[i];
    vector<ll> presum(N+1);
    for (int i=0; i<N; i++) presum[i+1] = presum[i] + A[i];

    if (presum[N] % 4 != 0) {
        cout<<0<<endl;
        return 0;
    }

    ll bucket_val = presum[N] / 4;

    vector<ll> ans(4);
    ans[0] = 1;

    for (int i=1; i<N; i++) {
        for (int j=3; j>=1; j--) {
            if (presum[i] == bucket_val * j) {
                ans[j] += ans[j-1];
            }
        }
    }
    cout<<ans[3]<<endl;
}