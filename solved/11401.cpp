#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define endl '\n'
using namespace std;
typedef unsigned long long ll;

const ll MOD = 1000000007LL;

ll fast_pow(ll b, ll e){
    ll ans = 1;
    while (e) {
        if (e % 2 == 1) {
            ans = ans * b;
            ans %= MOD;
        }
        b = b * b;
        b %= MOD;
        e /= 2;
    }
    return ans;
}
// ll inv_a = fast_pow(a, MOD-2);

ll nCr(ll n, ll r) {
    // n! / (n-r)! / r!
    ll num = 1; // n!/(n-r)! = n * n-1 * n-2 * ... * n-r
    ll den = 1; // r!
    for (ll i=n-r+1; i<=n; i++) {
        num *= i;
        num %= MOD;
    }
    for (ll i=1; i<=r; i++) {
        den *= i;
        den %= MOD;
    }
    return (num*fast_pow(den, MOD-2))%MOD;
}

int main() {
    fastio;
    
    ll N, R; cin>>N>>R;
    cout<<nCr(N, R)<<endl;
}