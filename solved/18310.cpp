#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) x.size()
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N; cin>>N;

    vector<int> A(N);
    for (int i=0; i<N; i++) cin>>A[i];

    sort(all(A));
    
    cout<<A[(N-1)/2]<<endl;
}