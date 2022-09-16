#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef long long ll;

int main() {
    fastio;
    
    int N; cin>>N;
    vector<int> A(N);
    for (int i=0; i<N; i++) cin>>A[i];

    // gcd of [ A[0], A[i] ]
    // gcd of [ A[i], A[N-1] ]
    vector<int> gcd_l(N), gcd_r(N);

    gcd_l[0] = A[0];
    for (int i=1; i<N; i++) gcd_l[i] = gcd(gcd_l[i-1], A[i]);

    gcd_r[N-1] = A[N-1];
    for (int i=N-2; i>=0; i--) gcd_r[i] = gcd(gcd_r[i+1], A[i]);

    int total_gcd = gcd_l[N-1];
    int max_gcd = -1;
    int k = -1;
    for (int i=0; i<N; i++) {
        int now = gcd(
            (i-1 >= 0) ? gcd_l[i-1] : gcd_r[i+1],
            (i+1 < N) ? gcd_r[i+1] : gcd_l[i-1]
        );
        if (total_gcd % now != 0) {
            if (max_gcd < now) {
                max_gcd = now;
                k = A[i];
            }
        }
    }
    if (k == -1) cout<<-1<<endl;
    else cout<<max_gcd<<' '<<k<<endl;
}