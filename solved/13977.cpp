#include <iostream>
#define endl '\n'
using namespace std;
typedef unsigned long long ull;
const ull M = 1000000007ULL;
ull mul(ull x, ull y) {
    ull res = 1;
    while (y > 0) {
        if (y % 2) {
            res *= x;
            res %= M;
        }
        x *= x;
        x %= M;
        y /= 2;
    }
    return res;
}
ull fac[4000001];
ull inv[4000001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m; cin>>m;
    fac[0] = 1;
    for (int j=1; j<=4000000; j++) {
        fac[j] = (fac[j-1] * j) % M;
    }
    inv[4000000] = mul(fac[4000000], M - 2)%M;
    for (int j=3999999; j>=0; j--) {
        inv[j] = (inv[j+1] * (j+1)) % M;
    }
    while (m--) {
        ull N, K; cin>>N>>K;
        cout<<(((fac[N]*inv[N-K])%M)*inv[K])%M<<endl;
    }
}
