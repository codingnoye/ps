#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define ff(i, s, e) for (int i=s; i<e; i++)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N; cin>>N;
    vector<int> a(N);

    ff(i, 0, N) cin>>a[i];

    sort(a.begin(), a.end());

    int aa = 0, bb = 0;

    for (int i=N-1; i>=0; i--) {
        if ((N-1-i) % 2 == 0) {
            aa += a[i];
        } else {
            bb += a[i];
        }
    }
    cout<<aa<<' '<<bb<<endl;
}