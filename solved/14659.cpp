#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N; cin>>N;
    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin>>A[i];
    }
    int ans = 0;
    for (int i=0; i<N-1; i++) {
        int res = 0;
        for (int j=i+1; j<N; j++) {
            if (A[i] <= A[j]) break;
            res++;
        }
        ans = max(res, ans);
    }
    cout<<ans<<endl;
}