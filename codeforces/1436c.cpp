#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef unsigned long long ull;
#define endl '\n'
const int MOD = 1000000007;

ull fac[1001];

ull fastmul(ull x, ull e) {
    ull r = 1;
    if (e&1) r = x;
    while (e) {
        e = e>>1;
        x = (x*x) % MOD;
        if (e&1) r = (r * x) % MOD;
    }
    return r;
}
ull inv(ull n) {
    return fastmul(n, MOD-2);
}
ull nCr(ull n, ull r) {
    return (((fac[n] * inv(fac[n-r])) % MOD) * inv(fac[r])) % MOD;
}
ull nPr(ull n, ull r) {
    return (fac[n] * inv(fac[n-r])) % MOD;
}
void solve() {
    fac[0] = 1;
    for (int i=1; i<1001; i++) fac[i] = (fac[i-1] * i) % MOD;
    ull N, X, P; cin>>N>>X>>P;

    ull l=0, r=N;
    ull lcnt=0, rcnt=0;
    while (l < r) {
        ull m = (l+r) / 2;
        if (m==P) break;
        else if (m<=P) {
            l = m+1;
            lcnt++;
        } else {
            r = m;
            rcnt++;
        }
    }
    /*
    ull res = nCr(X-1, lcnt);
    res = (res * nCr(N-X, rcnt)) % MOD;
    res = (res * fac[N-lcnt-rcnt-1]) % MOD;
    */
    ull res = nPr(X-1, lcnt);
    res = (res * nPr(N-X, rcnt)) % MOD;
    res = (res * fac[N-lcnt-rcnt-1]) % MOD;
    cout<<res<<endl;
    // X보다 작은 수들 중 수 lcnt개 고르기, 큰 수들 중 rcnt개 고르기, 나머지 nPr
    // (X-1) C lcnt * (N-X) C rcnt * (N-lcnt-rcnt)!

    // 2트: (X-1) P lcnt * (N-X) P rcnt * (N-lcnt-rcnt)!
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}